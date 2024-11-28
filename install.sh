#!/usr/bin/env bash

# Create Directories
cd "$HOME"
mkdir -p Documents Downloads Pictures Videos Music Workspaces Vaults/git

OG_PATH="$HOME/Vaults/git"
mv dotfiles $OG_PATH
cd $OG_PATH/dotfiles

# Update first
sudo pacman -Syu --noconfirm --needed base-devel

# Install fonts
sudo pacman -S --noconfirm --needed $(< packages/fonts.txt)

# Install the xorg
sudo pacman -S --noconfirm --needed $(< packages/core.txt)

# Install utility
sudo pacman -S --noconfirm --needed $(< packages/utility.txt)


# Changing default shell to zsh
ZSH_PATH=$(which zsh)
if [ -n "$ZSH_PATH" ]; then
    chsh -s "$ZSH_PATH"
else
    echo "zsh not installed"
    exit 1
fi

# Installing my neovim config
git clone https://github.com/taitesen/nvim.git $OG_PATH

# Installing yay AUR helper
if ! command -v yay &> /dev/null
then
    mkdir -p ~/.local/bin && cd ~/.local/bin
    git clone https://aur.archlinux.org/yay.git
    cd yay
    makepkg -si
fi

# Installing additional softwares via yay
yay -S --noconfirm ueberzugpp vesktop-bin picom-git

# Copying config files
cd $OG_PATH/dotfiles/config/
cp -r .xinitrc .zprofile .Xresources .tmux.conf $HOME

config_items=(
    "fastfetch"
    "zathura"
    "mpd"
    "ncmpcpp"
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
    "dwmblocks"
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

# Post-Installation
echo -e "Reboot now? [y/n]: \c"
read RESTART_CHOICE
REFINE_CHOICE=$(echo $RESTART_CHOICE | tr '[:upper:]' '[:lower:]')
if [[ $REFINE_CHOICE == "y" ]];then
    systemctl reboot
else
    echo "INSTALLATION FINISH. REBOOT TO SEE CHANGES."
fi
