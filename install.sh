#!/usr/bin/env bash

# Update first
sudo pacman -Syu --noconfirm --needed base-devel

# Install the xorg
sudo pacman -S --noconfirm --needed $(< packages/core.txt)

# Install utility
sudo pacman -S --noconfirm --needed $(< packages/utility.txt)

# Install fonts
sudo pacman -S --noconfirm --needed $(< packages/fonts.txt)

# Create Directories
cd "$HOME"
mkdir -p Documents Downloads Pictures Videos Music Workspaces Vaults

# Changing default shell to zsh
ZSH_PATH=$(which zsh)
if [ -n "$ZSH_PATH" ]; then
    chsh -s "$ZSH_PATH"
else
    echo "zsh not installed"
    exit 1
fi

# Installing my neovim config
mkdir -p $HOME/.config/nvim/
git clone https://github.com/taitesen/nvim.git $HOME/.config/nvim/

# Installing paru AUR helper
if ! command -v paru &> /dev/null
then
    cd /tmp/
    git clone https://aur.archlinux.org/paru.git
    cd paru
    makepkg -si
fi

# Installing additional softwares via paru
paru -S ueberzugpp vesktop-bin picom-git

# Cloning my dwm repo
mkdir -p $HOME/.local/ && cd $HOME/.local/
if ! git clone https://github.com/taitesen/dwm.git; then
    echo "Failed to clone dwm repository"
    exit 1
fi

rm -rf src/ && mv dwm/ src/

# Copying config files
cd src/config/
cp -r .tmux.conf .xinitrc .zprofile .Xresources $HOME/
mkdir -p $HOME/.config/zsh/
cp -r .zshrc $HOME/.config/zsh/

config_items=(
    "fastfetch"
    "kitty"
    "ohmyposh"
    "picom"
    "qutebrowser"
    "starship.toml"
    "vesktop"
    "yazi"
)
destination="$HOME/.config/"
for item in "${config_items[@]}"; do
    cp -r "$item" "$destination"
done


# Installing dwm environment
dirs=(
    "dwm"
    "dmenu"
    "slstatus"
    "st"
 )
for item in "${dirs[@]}"; do
    if [ -d "../$item" ]; then
        cd "../$item" || { echo "Failed to change direcory to ../$item"; exit 1; }
        sudo make clean install || { echo "Failed to make clean install in $item"; exit 1; }
    else
        echo "$item does not exits"
    fi
done


# Copying scripts to local bin
cd ../script/
mkdir -p $HOME/.local/bin/
scripts=(
    "battery"
    "clock"
    "heiham"
    "internet"
    "nettraf"
    "tmux-sessionizer"
    "volume"
    "personal/"
)
dests="$HOME/.local/bin/"
for item in "${scripts[@]}"; do
    cp -r "$item" "$dests"
done

# Moving wallpapers folders
cd ../
mv wallpapers/ $HOME/Pictures/
cd "$HOME"

# Post-Installation
echo -e "Reboot now? [y/n]: \c"
read RESTART_CHOICE
REFINE_CHOICE=$(echo $RESTART_CHOICE | tr '[:upper:]' '[:lower:]')
if [[ $REFINE_CHOICE == "y" ]];then
    systemctl reboot
else
    echo "INSTALLATION FINISH. REBOOT TO SEE CHANGES."
fi
