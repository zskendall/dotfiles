" Enable modern Vim features not compatible with Vi spec.
set nocompatible

let atgoogle = filereadable(glob('~/.vimrc_google'))

" ==============================================================================
" Configure plugins (e.g. - Vundle) here.
" ==============================================================================
filetype plugin indent on

call plug#begin('~/.vim/plugged')

" Plug 'scrooloose/nerdtree'
Plug 'mhinz/vim-signify'

call plug#end()

" Highlight colors in Signify {{{
highlight SignColumn ctermbg=none

" signs
highlight SignifySignAdd    cterm=bold ctermbg=none  ctermfg=119
highlight SignifySignDelete cterm=bold ctermbg=none  ctermfg=167
highlight SignifySignChange cterm=bold ctermbg=none  ctermfg=227
" }}}

" ==============================================================================
" Basic Options
" ==============================================================================

" Syntax highlighting
syntax on

" Highlight overlength lines
highlight OverLength ctermbg=red ctermfg=white guibg=#592929
augroup autohighlight
  autocmd!
  autocmd FileType * match OverLength /\%81v.\+/
  autocmd FileType java match OverLength /\%101v.\+/
augroup END

" text width
set tw=80

" line numbers down left
highlight LineNr ctermfg=grey
set number

" set tabs
augroup autotab
  autocmd!
  autocmd BufNewFile,BufRead set tabstop=2
  autocmd BufNewFile,BufRead set softtabstop=2
  autocmd BufNewFile,BufRead set shiftwidth=2
  autocmd BufNewFile,BufRead set expandtab
augroup END

if !atgoogle
  set tabstop=2
  set softtabstop=2
  set shiftwidth=2
  set expandtab
endif

autocmd BufNewFile,BufRead set fo+=t
autocmd BufNewFile,BufRead set tw=80

" map qq to Esc
inoremap qq <Esc>

" switch mapleader to comma
let mapleader=","

" add explore
nnoremap <leader>e :Explore<CR>

" map keys to comment and uncomment
augroup comment
  autocmd!
  autocmd FileType * map <C-C> :s:^\s*:\1\/\/ <CR>
  autocmd FileType * map <C-T> :s:^\s*\/\/:\1 <CR>
  autocmd FileType vim map <C-C> :s:^\s*:\1" <CR>
  autocmd FileType vim map <C-T> :s:":\1 <CR>
  autocmd FileType python map <C-C> :s:^\s*:\1# <CR>
  autocmd FileType python map <C-T> :s:^\s*#:\1 <CR>
augroup END 
" Map keys for movement: Alt-HJKL {{{
execute "set <A-J>=\ej"
execute "set <A-K>=\ek"
execute "set <A-L>=\el"
execute "set <A-H>=\eh"

" buffers
nnoremap <A-J> <C-W><C-J>
nnoremap <A-K> <C-W><C-K>
nnoremap <A-L> <C-W><C-L>
nnoremap <A-H> <C-W><C-H>

" insert
inoremap <A-J> <Down>
inoremap <A-K> <Up>
inoremap <A-L> <Right>
inoremap <A-H> <Left>

execute "set <A-E>=\ee"
inoremap <A-E> <End>

" Map keys for page up and page down
execute "set <A-U>=\eu"
execute "set <A-N>=\en"
nnoremap <A-U> <PageUp>
nnoremap <A-N> <PageDown>
" }}}

" ==============================================================================
" Status Line Functions and Creation
" ==============================================================================

" Build status: {{{
function! Status(winnum)
  let active = a:winnum == winnr()
  let bufnum = winbufnr(a:winnum)

  let stat = ''

  " set color of statusline content based on whether the buffer is active
  function! Color(active, num, content)
    if a:active
      return '%' . a:num . '*' . a:content .'%*'
    else
      return '%3*' . a:content
    endif
  endfunction

  " relative file path
  let stat .= Color(active, 4, active ? ' »' : ' «')
  let stat .= Color(active, 1, ' %<%f ')
  let stat .= Color(active, 4, active ? '«' : '»')

  " file modified and read-only flag
  let modified = getbufvar(bufnum, '&modified')
  let stat .= Color(active, 1, modified ? ' [+]' : '')
  let readonly = getbufvar(bufnum, '&readonly')
  let stat .= Color(active, 1, readonly ? ' [-]' : '')

  " show line number, column number, and percentage through file if in active
  " buffer
  if active
    " right side
    let stat .= '%-5.(%2*%)%='

    " row and column
    let stat .= '%-10.(%l,%c%V%) '

    " percentage through file
    let stat .= '%P%'
  endif

  return stat
endfunction
" }}}

" Status AutoCMD: {{{
function! s:RefreshStatus()
  for nr in range(1, winnr('$'))
    call setwinvar(nr, '&statusline', '%!Status(' . nr . ')')
  endfor
endfunction

augroup status
  autocmd!
  autocmd VimEnter,WinEnter,BufWinEnter * call <SID>RefreshStatus()
augroup end
" }}}

set laststatus=2

" Status Colors: {{{
hi User1 ctermfg=1 cterm=bold
hi User2 ctermfg=15
hi User3 ctermfg=250
hi User4 ctermfg=22 cterm=bold
" }}}

" Change User4 color when entering and leaving INSERT mode. {{{
function! InsertStatusLineColor(mode)
  if a:mode == 'r'
    hi User4 ctermfg=red cterm=bold
  elseif a:mode == 'i'
    hi User4 ctermfg=27 cterm=bold
  else
    hi User4 ctermfg=122 cterm=bold
  endif
endfunction

au InsertEnter * call InsertStatusLineColor(v:insertmode)
au InsertChange * call InsertStatusLineColor(v:insertmode)
au InsertLeave * hi User4 ctermfg=22 cterm=bold
" }}}

if (atgoogle)
  source ~/.vimrc_google
endif
