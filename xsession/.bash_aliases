# Logout of session from terminal emulator
ME=$(whoami)
alias xss='pkill -u $ME'

# Emacs in terminal, if you want to use emacs
alias emacs='emacs -nw'

# Run custom tmux startup script.
alias tms='~/tmux/session'

# Get to windows home dir. Check host, default to laptop
to_win() {
    WIN_HOME='/mnt/c/Users/zsken'
    if [ "$HOSTNAME" = "GreyGhost" ]; then
        WIN_HOME='/mnt/d/My Stuff'
    fi
    cd "$WIN_HOME"
}
alias wh=to_win

alias moo='/usr/games/cowsay'

# Occasional Nautilus problem freezing workspace in Ubuntu
alias naf='nautilus --no-desktop'
