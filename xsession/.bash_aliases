# Logout of session from terminal emulator
ME=$(whoami)
alias xss='pkill -u $ME'

# Run custom tmux startup script.
alias tms='~/tmux/session'

title() {
  PROMPT_COMMAND="echo -ne \"\033]0;$1\007\""
}

alias ll='ls -la'

source .aliases.$(hostname)
