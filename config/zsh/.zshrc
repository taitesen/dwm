eval "$(zoxide init zsh)"
eval "$(fzf --zsh)"
# eval "$(oh-my-posh init zsh --config $HOME/.config/ohmyposh/zen.toml)"
eval "$(starship init zsh)"

zmodload zsh/complist
autoload -U compinit && compinit
autoload -U colors && colors

export GPG_TTY=$(tty)

# LS COLORS
if [ -f "$HOME/.dircolors-database" ]; then
    eval "$(dircolors -b "$HOME/.dircolors-database")"
else
    eval "$(dircolors -b)"
fi
export LS_COLORS

alias l='eza -lh --git --no-time --no-filesize --group-directories-first --color=always --icons=always  --no-quotes'
alias ld='eza -D --color=always --icons=always --no-quotes'
alias ll='eza -Shl --git --total-size --no-time --group-directories-first --color=always --icons=always  --no-quotes'
alias lt='eza -xT -L2 --group-directories-first --color=always --icons=always  --no-quotes'
alias ls='eza -x --color=always --icons=always --no-quotes'
alias la='ls -ad .?* --no-quotes --group-directories-first'
alias tree='lt --no-quotes'
alias refresh='xset r rate 300 60; source ~/Vaults/git/dotfiles/config/zsh/.zshrc; xrdb ~/Vaults/git/dotfiles/config/.Xresources'
alias list='fc-list | sed -e "s/^[^:]*://g"'
alias gd='git diff --color-moved'
alias gl="git log --all --graph --pretty=format:'%C(magenta)%h%C(white) %an %ar%C(auto) %D%n%s%n'"
alias update-mirror='sudo reflector --latest 10 --sort rate --save /etc/pacman.d/mirrorlist'

# very important
alias nvim='XDG_CONFIG_HOME=/home/taitesen/Vaults/git nvim'

# brightness and volume
bup(){ brightnessctl set "$1%+" }
bdown(){ brightnessctl set "$1%-" }
vup(){ wpctl set-volume @DEFAULT_AUDIO_SINK@ "$1%+" }
vdown(){ wpctl set-volume @DEFAULT_AUDIO_SINK@ "$1%-" }

# zsh env loading
if [ -f ~/.env ]; then
    export $(cat ~/.env | xargs)
fi

bindkey -e
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
