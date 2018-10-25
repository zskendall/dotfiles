# Logout of session from terminal emulator
ME=$(whoami)
alias xss='pkill -u $ME'

# Emacs in terminal, if you want to use emacs
alias emacs='emacs -nw'

# Run custom tmux startup script.
alias tms='~/tmux/session'

if [ -z "$TMUX" ]; then
~/tmux/session
fi
