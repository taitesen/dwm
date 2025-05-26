#!/usr/bin/env bash

# Create Directories
cd "$HOME" || exit
mkdir -p Documents Downloads Pictures Videos Music Workspaces Vaults/git

OG_PATH="$HOME/Vaults/git"
mv dotfiles "$OG_PATH"
cd "$OG_PATH/dotfiles" || exit

# Update first
sudo pacman -Syu --noconfirm --needed base-devel

# Install fonts
sudo pacman -S --noconfirm --needed "$(< packages/fonts.txt)"

# Install the xorg
sudo pacman -S --noconfirm --needed "$(< packages/core.txt)"

# Install utility
sudo pacman -S --noconfirm --needed "$(< packages/utility.txt)"

# Install nvidia-utils
sudo pacman -S --noconfirm --needed "$(< packages/nvidia-utils.txt)"

# Install c progarmming tools
sudo pacman -S --noconfirm --needed "$(< packages/dev.txt)"

# Installing yay AUR helper
if ! command -v yay &> /dev/null
then
    mkdir -p ~/.local/bin && cd ~/.local/bin || exit
    git clone https://aur.archlinux.org/yay.git
    cd yay || exit
    makepkg -si
fi

# Installing additional softwares via yay
yay -S --noconfirm ueberzugpp vesktop-bin picom-git libva-nvidia-driver-git

# Copying config files
cd "$OG_PATH/dotfiles/config/" || exit
cp -r ".fehbg" ".zprofile" "$HOME"

config_items=(
    "bat"
    "cava"
    "fastfetch"
    "kitty"
    "mpd"
    "ncmpcpp"
    "picom"
    "qutebrowser"
    "vesktop"
    "yazi"
    "zathura"
    "starship.toml"
)
destination="$HOME/.config/"
for item in "${config_items[@]}"; do
    cp -r "$item" "$destination"
done

# Installing dwm environment
dirs=(
    "dwm"
    "dmenu"
    "dwmblocks"
    "st"
 )
for item in "${dirs[@]}"; do
    if [[ -d "../$item" ]]; then
        cd "../$item" || { echo "[!] Failed to change direcory to ../$item"; exit 1; }
        sudo make clean install || { echo "[!] Failed to make clean install in $item"; exit 1; }
    else
        echo "[!] $item does not exits"
    fi
done

# Installing my neovim config
git clone https://github.com/taitesen/nvim.git "$OG_PATH"

# Installing tmux TPM plugin manager
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

# Changing default shell to zsh
ZSH_PATH=$(which zsh)
if [[ -n "$ZSH_PATH" ]]; then
    curl -sS https://starship.rs/install.sh | sh || { echo "[!] failed to install starship"; exit 1; }
    chsh -s "$ZSH_PATH" "$USER" || { echo "[!] failed to change shell to zsh"; exit 1;}
fi

# bat preview theme
bat cache --build

# Post-Installation
echo -e "Reboot now? [y/n]: \c"
read -r RESTART_CHOICE
REFINE_CHOICE=$(echo "$RESTART_CHOICE" | tr '[:upper:]' '[:lower:]')
if [[ $REFINE_CHOICE == "y" ]];then
    systemctl reboot
else
    echo "INSTALLATION FINISH. REBOOT TO SEE CHANGES."
fi
