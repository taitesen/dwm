# DOTFILES
DWM + Arch Linux

## PREREQUISITES
- **curl**: To download necessary files
- **git**: To clone repositories
- **bash**: To execute the installation script

```bash
sudo pacman -S --noconfirm --needed git curl
```
## INSTALLATION
#### 1. CLONE THE REPOSITORY
Clone this repository into your home directory:
```bash
git clone https://github.com/taitesen/dwm.git ~/dotfiles
cd ~/dotfiles
```
#### 2. RUN THE INSTALLATION SCRIPT
The provided install.sh script will automate the installation of required packages, dependencies, and configurations.

Make the script executable and run it:
```bash
sudo chmod +x install.sh
./install.sh
```
---
## KEYBINDINGS
**Here are some important keybindings:** Window-key is the default modifier key. <br>

**WINDOW MANAGEMENT** <br>
<kbd>Mod + Enter</kbd>: Spawn terminal <br>
<kbd>Mod + Space</kbd>: Spawn dmenu <br>
<kbd>Mod + c</kbd>: Kill client <br>
<kbd>Mod + ,</kbd>: Previous window <br>
<kbd>Mod + .</kbd>: Next window <br>
**TAG NAVIGATION** <br>
<kbd>Mod + u</kbd>: Jump to 1st window tag <br>
<kbd>Mod + i</kbd>: Jump to 2nd window tag <br>
<kbd>Mod + o</kbd>: Jump to 3rd window tag <br>
<kbd>Mod + p</kbd>: Jump to 4th window tag <br>
<kbd>Mod + h</kbd>: Jump to 5th window tag <br>
<kbd>Mod + j</kbd>: Jump to 6th window tag <br>
<kbd>Mod + k</kbd>: Jump to 7th window tag <br>
<kbd>Mod + l</kbd>: Jump to 8th window tag <br>
<kbd>Mod + n</kbd>: Jump to 9th window tag <br>
<kbd>Mod +Shift + u</kbd>: Send the current client to 1st window tag <br>
<kbd>Mod +Shift + i</kbd>: Send the current client to 2st window tag <br>
<kbd>Mod +Shift + o</kbd>: Send the current client to 3st window tag <br>
And so on..<br>
**MISCELLANEOUS** <br>
<kbd>Mod + Shift + b</kbd>: Toggle blur <br>
<kbd>Mod + b</kbd>: Toggle bar <br>
<kbd>Mod + y</kbd>: Search videos on youtube using zen-browser<br>
<kbd>Mod + Shift + y</kbd>: open pdf on zathura<br>
<kbd>Mod + r</kbd>: Records screen using ffmpeg<br>
<kbd>Mod + r</kbd>: Again to stop screen using<br>
<kbd>Mod + Shift + r</kbd>: Used after screen recoding is stop<br>
<kbd>Mod + Shift + w</kbd>: Quickmarks for zen-browser<br>
<kbd>Mod + Shift + c</kbd>: simple password manager<br>
<kbd>Mod + Shift + Space</kbd>: copy password to clipboard<br>
<kbd>Mod + m</kbd>: Search on google using zen-browser<br>
<kbd>Mod + Shift + m</kbd>: Paste url link to open using zen-browser<br>
<kbd>Mod + v</kbd>: clipboard history<br>
<kbd>Mod + x</kbd>: add selected/highligted to clipboard<br>
**TMUX PREFIX KEY** <br>
<kbd>Alt + Space</kbd>

---
## CONCLUSION
This repository contains my custom build of dwm along with configuration files and patches. It is designed for quick setup and portability across my personal machines.

