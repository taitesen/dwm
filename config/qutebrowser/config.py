config.load_autoconfig(False)

config.set("content.cookies.accept", "all", "chrome-devtools://*")

config.set("content.cookies.accept", "all", "devtools://*")

config.set("content.headers.accept_language", "", "https://matchmaker.krunker.io/*")

config.set(
    "content.headers.user_agent",
    "Mozilla/5.0 ({os_info}) AppleWebKit/{webkit_version} (KHTML, like Gecko) {upstream_browser_key}/{upstream_browser_version} Safari/{webkit_version}",
    "https://web.whatsapp.com/",
)

config.set(
    "content.headers.user_agent",
    "Mozilla/5.0 ({os_info}; rv:90.0) Gecko/20100101 Firefox/90.0",
    "https://accounts.google.com/*",
)

config.set("content.images", True, "chrome-devtools://*")

config.set("content.images", True, "devtools://*")


config.set("content.javascript.enabled", True, "chrome-devtools://*")

config.set("content.javascript.enabled", True, "devtools://*")

config.set("content.javascript.enabled", True, "chrome://*/*")

config.set("content.javascript.enabled", True, "qute://*/*")

config.set(
    "content.local_content_can_access_remote_urls",
    True,
    "file:///home/taitesen/.local/share/qutebrowser/userscripts/*",
)

config.set(
    "content.local_content_can_access_file_urls",
    True,
    "file:///home/taitesen/.local/share/qutebrowser/userscripts/*",
)

c.content.javascript.clipboard = "access-paste"

c.hints.border = "1px solid #000000"

c.scrolling.bar = "never"

c.scrolling.smooth = True

c.statusbar.show = "in-mode"

c.tabs.show = "always"

c.colors.completion.fg = "#6b6b6b"

c.colors.completion.odd.bg = "#000000"

c.colors.completion.even.bg = "#000000"

c.colors.completion.category.fg = "#a6e3a1"

c.colors.completion.category.bg = "#000000"

c.colors.completion.category.border.top = "#000000"

c.colors.completion.category.border.bottom = "#000000"

c.colors.completion.item.selected.fg = "#cdd6f4"

c.colors.completion.item.selected.bg = "#585b70"

c.colors.completion.item.selected.border.top = "#585b70"

c.colors.completion.item.selected.border.bottom = "#585b70"

c.colors.completion.item.selected.match.fg = "#ebbcba"

c.colors.completion.match.fg = "#cdd6f4"

c.colors.completion.scrollbar.fg = "#ebbcba"

c.colors.completion.scrollbar.bg = "#000000"

c.colors.contextmenu.menu.bg = "#000000"

c.colors.contextmenu.menu.fg = "#ebbcba"

c.colors.contextmenu.selected.bg = "#ebbcba"

c.colors.contextmenu.selected.fg = "#000000"

c.colors.contextmenu.disabled.bg = "#181825"

c.colors.contextmenu.disabled.fg = "#6c7086"

c.colors.downloads.bar.bg = "#1e1e2e"

c.colors.downloads.start.fg = "#89b4fa"

c.colors.downloads.start.bg = "#1e1e2e"

c.colors.downloads.stop.fg = "#a6e3a1"

c.colors.downloads.stop.bg = "#1e1e2e"

c.colors.downloads.system.fg = "none"

c.colors.downloads.system.bg = "none"

c.colors.downloads.error.fg = "#f38ba8"

c.colors.downloads.error.bg = "#1e1e2e"

c.colors.hints.bg = "#181825"

c.colors.hints.fg = "#ebbcba"

c.colors.hints.match.fg = "#bac2de"

c.colors.keyhint.fg = "#cdd6f4"

c.colors.keyhint.suffix.fg = "#bac2de"

c.colors.keyhint.bg = "#181825"

c.colors.messages.error.fg = "#f38ba8"

c.colors.messages.error.bg = "#6c7086"

c.colors.messages.error.border = "#181825"

c.colors.messages.warning.fg = "#fab387"

c.colors.messages.warning.bg = "#6c7086"

c.colors.messages.warning.border = "#181825"

c.colors.messages.info.fg = "#ebbcba"

c.colors.messages.info.bg = "#000000"

c.colors.messages.info.border = "#181825"

c.colors.prompts.fg = "#ebbcba"

c.colors.prompts.border = "1px solid #6c7086"

c.colors.prompts.bg = "#181825"

c.colors.prompts.selected.fg = "#f5e0dc"

c.colors.prompts.selected.bg = "#585b70"

c.colors.statusbar.normal.fg = "#ebbcba"

c.colors.statusbar.normal.bg = "#000000"

c.colors.statusbar.insert.fg = "#ebbcba"

c.colors.statusbar.insert.bg = "#000000"

c.colors.statusbar.passthrough.fg = "#fab387"

c.colors.statusbar.passthrough.bg = "#1e1e2e"

c.colors.statusbar.private.fg = "#bac2de"

c.colors.statusbar.private.bg = "#181825"

# Foreground color of the statusbar in command mode.
# Type: QssColor
c.colors.statusbar.command.fg = "#ebbcba"

# Background color of the statusbar in command mode.
# Type: QssColor
c.colors.statusbar.command.bg = "#000000"

# Foreground color of the statusbar in private browsing + command mode.
# Type: QssColor
c.colors.statusbar.command.private.fg = "#bac2de"

# Background color of the statusbar in private browsing + command mode.
# Type: QssColor
c.colors.statusbar.command.private.bg = "#1e1e2e"

# Foreground color of the statusbar in caret mode.
# Type: QssColor
c.colors.statusbar.caret.fg = "#fab387"

# Background color of the statusbar in caret mode.
# Type: QssColor
c.colors.statusbar.caret.bg = "#1e1e2e"

# Foreground color of the statusbar in caret mode with a selection.
# Type: QssColor
c.colors.statusbar.caret.selection.fg = "#fab387"

# Background color of the statusbar in caret mode with a selection.
# Type: QssColor
c.colors.statusbar.caret.selection.bg = "#1e1e2e"

# Background color of the progress bar.
# Type: QssColor
c.colors.statusbar.progress.bg = "#1e1e2e"

# Default foreground color of the URL in the statusbar.
# Type: QssColor
c.colors.statusbar.url.fg = "#cdd6f4"

# Foreground color of the URL in the statusbar on error.
# Type: QssColor
c.colors.statusbar.url.error.fg = "#f38ba8"

# Foreground color of the URL in the statusbar for hovered links.
# Type: QssColor
c.colors.statusbar.url.hover.fg = "#89dceb"

# Foreground color of the URL in the statusbar on successful load
# (http).
# Type: QssColor
c.colors.statusbar.url.success.http.fg = "#94e2d5"

# Foreground color of the URL in the statusbar on successful load
# (https).
# Type: QssColor
c.colors.statusbar.url.success.https.fg = "#a6e3a1"

# Foreground color of the URL in the statusbar when there's a warning.
# Type: QssColor
c.colors.statusbar.url.warn.fg = "#f9e2af"

# Background color of the tab bar.
# Type: QssColor
c.colors.tabs.bar.bg = "#000000"

# Color for the tab indicator on errors.
# Type: QtColor
c.colors.tabs.indicator.error = "#f38ba8"

# Color gradient interpolation system for the tab indicator.
# Type: ColorSystem
# Valid values:
#   - rgb: Interpolate in the RGB color system.
#   - hsv: Interpolate in the HSV color system.
#   - hsl: Interpolate in the HSL color system.
#   - none: Don't show a gradient.
c.colors.tabs.indicator.system = "none"

# Foreground color of unselected odd tabs.
# Type: QtColor
c.colors.tabs.odd.fg = "#6b6b6b"

# Background color of unselected odd tabs.
# Type: QtColor
c.colors.tabs.odd.bg = "#3b3b3b"

# Foreground color of unselected even tabs.
# Type: QtColor
c.colors.tabs.even.fg = "#6b6b6b"

# Background color of unselected even tabs.
# Type: QtColor
c.colors.tabs.even.bg = "#3b3b3b"

# Foreground color of selected odd tabs.
# Type: QtColor
c.colors.tabs.selected.odd.fg = "#ebbcba"

# Background color of selected odd tabs.
# Type: QtColor
c.colors.tabs.selected.odd.bg = "#000000"

# Foreground color of selected even tabs.
# Type: QtColor
c.colors.tabs.selected.even.fg = "#ebbcba"

# Background color of selected even tabs.
# Type: QtColor
c.colors.tabs.selected.even.bg = "#000000"

c.zoom.default = "150%"

# Background color for webpages if unset (or empty to use the theme's
# color).
# Type: QtColor
c.colors.webpage.bg = "#000000"

c.colors.webpage.darkmode.enabled = True

c.fonts.default_size = "20px"
c.fonts.web.size.default = 20

c.completion.height = "20%"
c.tabs.favicons.scale = 1.1
c.tabs.padding = {"bottom": 4, "left": 7, "right": 7, "top": 4}
c.fonts.default_family = "FreeSans"

# Bindings for normal mode
config.bind("e", "hint links spawn mpv {hint-url}")
