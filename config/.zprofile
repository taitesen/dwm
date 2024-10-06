# Profile file. Runs on login. Environmenta variables are set here

# Add `~/.local/bin` to $PATH
export PATH="$PATH:$HOME/.local/bin/:$HOME/.local/bin/personal/:$HOME/usr/share/"

# Default programs
export TERMINAL="st"
export EDITOR="nvim"
export BROWSER="firefox-developer-edition"
export READER="zathura"

# PINK
# export LS_COLORS="di=38;5;14"

# BLUE
# export LS_COLORS="di=38;5;39"

# GREEN
# export LS_COLORS="di=38;5;108"

export ZDOTDIR="$HOME/.config/zsh"
export ds=/home/taitesen/Vaults/dataStructure/
export dot=/home/taitesen/.local/src/
export socket=/home/taitesen/Vaults/project/socket/

# MPD daemon start (if no other user instance exists)
# [ ! -s ~/.config/mpd/pid ] && mpd

// This needs to lived here
alias refresh='xset r rate 300 60; source $dot/config/.zshrc ~/.zprofile; xrdb ~/.Xresources'

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
  exec startx &>/dev/null
fi

