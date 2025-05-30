# Profile file. Runs on login. Environmenta variables are set here

export PATH="$PATH:$HOME/Vaults/git/dotfiles/script/:$HOME/Vaults/git/dotfiles/script/personal/:$HOME/usr/share/"
export PAGER=less

# Default programs
export EDITOR="nvim"
export BROWSER="firefox"
export READER="zathura"

export BAT_THEME="rose-pine-moon"
export WEZTERM_CONFIG_FILE="$HOME/Vaults/git/dotfiles/config/wezterm/wezterm.lua"
export ZDOTDIR="$HOME/Vaults/git/dotfiles/config/zsh"
export XINITRC="$HOME/Vaults/git/dotfiles/config/.xinitrc"
export XRESOURCES="$HOME/Vaults/git/dotfiles/config/.Xresources"
export ds=$HOME/Vaults/git/dataStructure
export dot=$HOME/Vaults/git/dotfiles
export socket=$HOME/Vaults/git/socket
export git=$HOME/Vaults/git

# MPD daemon start (if no other user instance exists)
[ ! -s ~/.config/mpd/pid ] && mpd

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
  exec startx &>/dev/null
fi
