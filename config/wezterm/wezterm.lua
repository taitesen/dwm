-- Pull in the wezterm API
local wezterm = require("wezterm")

-- This will hold the configuration.
local config = wezterm.config_builder()

-- This is where you actually apply your config choices
config.font = wezterm.font("IosevkaTerm Nerd Font Propo", {weight="Light", stretch="Normal", style="Normal"})
config.font_size = 19

config.enable_tab_bar = false

config.window_decorations = "RESIZE"

config.window_background_opacity = 0.8

config.colors = {
	foreground = "#999999",
	background = "#000000",
	cursor_bg = "#ebbcba",
	cursor_border = "#ebbcba",
	cursor_fg = "#1b1b1b",
	selection_bg = "#ebbcba",
	selection_fg = "#999999",
	ansi = { "#1f1d2e", "#eb6f92", "#f6c177", "#ebbcba", "#31748f", "#c4a7e7", "#9ccfd8", "#6e6a86" },
	brights = { "#26233a", "#eb6f92", "#f6c177", "#ebbcba", "#31748f", "#c4a7e7", "#9ccfd8", "#908caa" },
}

config.keys = {
    { key = "c", mods = "ALT", action = wezterm.action.CopyTo("Clipboard") },
    { key = "v", mods = "ALT", action = wezterm.action.PasteFrom("Clipboard") },
    { key = "j", mods = "ALT", action = wezterm.action.ScrollByPage(1) },  -- Scroll down
    { key = "k", mods = "ALT", action = wezterm.action.ScrollByPage(-1) }, -- Scroll up
}
-- and finally, return the configuration to wezterm
return config
