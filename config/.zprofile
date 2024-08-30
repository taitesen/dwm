# Profile file. Runs on login. Environmenta variables are set here

# Add `~/.local/bin` to $PATH
export PATH="$PATH:$HOME/.local/bin/:$HOME/local/bin/personal/:$HOME/usr/share/"

# Default programs
export TERMINAL="st"
export EDITOR="nvim"
export BROWSER="qutebrowser"
export READER="zathura"

export ZDOTDIR="$HOME/.config/zsh"
export LS_COLORS="di=38;5;217"
export ds=/home/taitesen/Vaults/dataStructure/

# MPD daemon start (if no other user instance exists)
# [ ! -s ~/.config/mpd/pid ] && mpd

xrdb /home/taitesen/.local/src/st/Xdefaults

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
  exec startx &>/dev/null
fi

