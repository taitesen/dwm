# Profile file. Runs on login. Environmenta variables are set here

export PATH="$PATH:$HOME/Vaults/git/dotfiles/script/:$HOME/Vaults/git/dotfiles/script/personal/:$HOME/usr/share/"
export PAGER=less

# Default programs
export EDITOR="nvim"
export BROWSER="zen-browser"
export READER="zathura"

export BAT_THEME="rose-pine-moon"
export WEZTERM_CONFIG_FILE="$HOME/Vaults/git/dotfiles/config/wezterm/wezterm.lua"
export ZDOTDIR="$HOME/Vaults/git/dotfiles/config/zsh"
export ds=$HOME/Vaults/git/dataStructure
export dot=$HOME/Vaults/git/dotfiles
export socket=$HOME/Vaults/git/socket
export git=$HOME/Vaults/git

# MPD daemon start (if no other user instance exists)
[ ! -s ~/.config/mpd/pid ] && mpd

# This needs to lived here
alias refresh='xset r rate 300 60; source $dot/config/zsh/.zshrc ~/.zprofile; xrdb ~/.Xresources; sudo reflector --latest 10 --sort rate --save /etc/pacman.d/mirrorlist'

if [[ -z $DISPLAY ]] && [[ $(tty) = /dev/tty1 ]]; then
  exec startx &>/dev/null
fi
