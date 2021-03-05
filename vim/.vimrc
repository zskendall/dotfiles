" Enable modern Vim features not compatible with Vi spec.
set nocompatible

" ==============================================================================
" Configure plugins (e.g. - Vundle) here.
" ==============================================================================
filetype plugin indent on

call plug#begin('~/.vim/plugged')

Plug 'scrooloose/nerdcommenter'
Plug 'mhinz/vim-signify'
Plug 'RRethy/vim-illuminate'
Plug 'raimondi/delimitmate'
Plug 'markonm/traces.vim'

Plug 'tsiemens/vim-aftercolors'

" Source any machine-specific plugins
if filereadable(glob('~/.vim.plugins.$HOSTNAME'))
  source ~/.vim.plugins.$HOSTNAME
endif

call plug#end()

" Highlight colors in Signify {{{
highlight SignColumn ctermbg=none

" signs
highlight SignifySignAdd    cterm=bold ctermbg=none  ctermfg=119
highlight SignifySignDelete cterm=bold ctermbg=none  ctermfg=167
highlight SignifySignChange cterm=bold ctermbg=none  ctermfg=227
" }}}

" Highlight spec for vim-illuminate
highlight Illum ctermbg=237
hi link illuminatedWord Illum

" Configurations for NerdCommenter {{{
" Spaces after comment delimiters by default
let g:NERDSpaceDelims = 1

" Allow commenting and inverting empty lines (useful for commenting region)
let g:NERDCommentEmptyLines = 1

" Enable trimming trailing whitespace when uncommenting
let g:NERDTrimTrailingWhitespace = 1
" }}}

" Highlight for the search term used by traces.vim.
hi Search ctermbg=159

" ==============================================================================
" Basic Options
" ==============================================================================

" Syntax highlighting
syntax on

" Change visual highlight to dark because WHITE???
hi Visual ctermbg=235 ctermfg=none

" change some colors to also support lighter backgrounds
hi Constant ctermfg=Yellow
hi Statement ctermfg=DarkGreen

" Highlight overlength lines
highlight OverLength ctermbg=88 ctermfg=15 guibg=#592929
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
set tabstop=2
set softtabstop=2
set shiftwidth=2
set expandtab

autocmd BufNewFile,BufRead set fo+=t
autocmd BufNewFile,BufRead set tw=80

" map qq to Esc
inoremap qq <Esc>

" switch mapleader to comma
let mapleader=","

" add explore
nnoremap <leader>e :Explore<CR>

" highlight next search match
set incsearch

" yank to EOL
nnoremap Y y$

" always open split buffer below
set splitbelow

" Map keys for movement: {{{
execute "set <A-J>=\ej"
execute "set <A-K>=\ek"
execute "set <A-L>=\el"
execute "set <A-H>=\eh"

" buffers Alt-HJKL
nnoremap <A-J> <C-W><C-J>
nnoremap <A-K> <C-W><C-K>
nnoremap <A-L> <C-W><C-L>
nnoremap <A-H> <C-W><C-H>

" insert Alt-HJKL
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

" previous and next cursor placement
execute "set <A-O>=\eo"
execute "set <A-I>=\ei"
nnoremap <A-O> <C-O>
nnoremap <A-I> <C-I>
" }}}

" Add some convenience searching
execute "set <A-;>=\e;"
nnoremap <A-;> *

" Fix weird characters sometimes being inserted with i-Esc-i in quick succession
set ttimeoutlen=0

" ==============================================================================
" Status Line Functions and Creation
" ==============================================================================

" Split bar: {{{
" borealis: 114,0
" nikhita: 90
" chjara: 88
" maqi: 88
" astral: 75
" autumnal: 202
set fillchars+=vert:│
hi VertSplit cterm=none ctermfg=88
" }}}

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
    hi User4 ctermfg=88 cterm=bold
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

" ==============================================================================
" Machine-specific Configuration
" ==============================================================================
if filereadable(glob('~/.vimrc.$HOSTNAME'))
  source ~/.vimrc.$HOSTNAME
endif
