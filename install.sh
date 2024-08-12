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
git clone https://github.com/taitesen/dwm.git
mv dwm/ src/

# Copying config files
cd src/config/
cp -r .tmux.conf .xinitrc .zprofile $HOME/
mkdir -p $HOME/.config/zsh/
cp -r .zshrc $HOME/.config/zsh/
cp -r kitty $HOME/.config/
cp -r ohmyposh $HOME/.config/

# Installing dwm environment
cd ../dwm/ && sudo make clean install
cd ../dmenu/ && sudo make clean install
cd ../dwmblocks/ && sudo make clean install
cd ../st/ && sudo make clean install

# Copying scripts to local bin
cd ../script/
mkdir -p $HOME/.local/bin/
cp -r battery clock heiham internet nettraf tmux-sessionizer volume $HOME/.local/bin/

# Moving wallpapers folders
cd ../
mv wallpapers/ $HOME/Pictures/
cd "$HOME"

# Changing default shell to zsh
ZSH_PATH=$(which zsh)
chsh -s "$ZSH_PATH"

# Installing my neovim config
mkdir -p $HOME/.config/nvim/
git clone https://github.com/taitesen/nvim.git $HOME/.config/nvim/

# Post-Installation
echo -e "Reboot now? [y/n]: \c"
read RESTART_CHOICE
REFINE_CHOICE=$(echo $RESTART_CHOICE | tr '[:upper:]' '[:lower:]')
if [[ $REFINE_CHOICE == "y" ]];then
    systemctl reboot
else
    echo "INSTALLATION FINISH. REBOOT TO SEE CHANGES."
fi
