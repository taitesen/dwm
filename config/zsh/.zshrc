eval "$(zoxide init zsh)"
eval "$(fzf --zsh)"
# eval "$(oh-my-posh init zsh --config $HOME/.config/ohmyposh/zen.toml)"
eval "$(starship init zsh)"

alias l='eza -lh --git --no-time --no-filesize --group-directories-first --color=always --icons=always  --no-quotes'
alias ld='eza -D --color=always --icons=always --no-quotes'
alias ll='eza -Shl --git --total-size --no-time --group-directories-first --color=always --icons=always  --no-quotes'
alias lt='eza -xT -L2 --group-directories-first --color=always --icons=always  --no-quotes'
alias ls='eza -x --color=always --icons=always --no-quotes'
alias la='ls -ad .?* --no-quotes --group-directories-first'
alias tree='lt --no-quotes'
alias refresh='xset r rate 300 60; source $dot/config/zsh/.zshrc ~/.zprofile; xrdb ~/.Xresources'
alias nvim='XDG_CONFIG_HOME=/home/taitesen/Vaults/git nvim'
alias list='fc-list | sed -e "s/^[^:]*://g"'

bindkey -e

autoload -U compinit
compinit

if [ -f ~/.env ]; then
    export $(cat ~/.env | xargs)
fi

bup(){
    brightnessctl set "$1%+"
}
bdown(){
    brightnessctl set "$1%-"
}

vup(){
    wpctl set-volume @DEFAULT_AUDIO_SINK@ "$1%+"
}

vdown(){
    wpctl set-volume @DEFAULT_AUDIO_SINK@ "$1%-"
}

source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
