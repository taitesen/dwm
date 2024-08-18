#!/usr/bin/env bash

# Update function
pacman -Syu --noconfirm --needed base-devel

# Update the system
pacman -Syu --needed --noconfirm xorg-xinit xorg-server xorg-xrandr \
    xorg-xsetroot libxft libxinerama firefox-developer-edition feh fastfetch \
    neovim zsh zsh-syntax-highlighting curl git wget unzip fzf nsxiv \
    man-db mpc mpd mpv ncmpcpp python3 python-pip python-pynvim npm \
    ttf-font-awesome ttf-terminus-nerd  ttf-jetbrains-mono-nerd \
    ttf-firacode-nerd zathura zathura-pdf-mupdf tmux meson ninja yazi \
    flameshot ffmpeg yt-dlp eza zoxide fd ripgrep htop openssl openssh \
    python-isort bat brightnessctl qutebrowser xclip xsel

# Create Directories
cd "$HOME"
mkdir -p Documents Downloads Pictures Videos Music Workspaces Vaults

# Changing default shell to zsh
ZSH_PATH=$(which zsh)
chsh -s "$ZSH_PATH"

# Installing my neovim config
mkdir -p $HOME/.config/nvim/
git clone https://github.com/taitesen/nvim.git $HOME/.config/nvim/

# Installing paru AUR helper
if ! command -v paru &> /dev/null
then
    cd /tmp/
    git clone https://aur.archlinux.org/paru.git
    cd paru
    makepkg -si --noconfirm
fi

# Installing additional softwares via paru
paru -S \
    ueberzugpp \
    vesktop-bin \
    picom-git \
    --noconfirm

# Cloning my dwm repo
mkdir -p $HOME/.local/ && cd $HOME/.local/
if ! git clone https://github.com/taitesen/dwm.git; then
    echo "Failed to clone dwm repository"
    exit 1
fi
mv dwm/ src/

# Copying config files
cd src/config/
cp -r .tmux.conf .xinitrc .zprofile $HOME/
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
    if [ -d "../$dirs" ]; then
        cd "../$dirs" || { echo "Failed to change direcory to ../$dirs"; exit 1; }
        sudo make clean install || { echo "Failed to make clean install in $dir"; exit 1; }
    else
        echo "$dirs does not exits"
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
