#!/bin/sh
if [ -z "${DBUS_SESSION_BUS_ADDRESS:-}" ]; then
    exec dbus-run-session "$0" "$@"
fi
export PATH="$HOME/.local/bin:$PATH"
export QT_QPA_PLATFORM=xcb
export _JAVA_AWT_WM_NONREPARENTING=1
export XDG_SESSION_TYPE=x11
export XDG_CURRENT_DESKTOP=dwm
xrdb -load "$HOME/.Xresources"
urxvtd -q -o -f
setxkbmap tr -option ctrl:nocaps
xset s 300 300 +dpms s blank
xset dpms 0 0 300
xsetroot -solid '#000000'
command -v xsettingsd >/dev/null && xsettingsd &
command -v nm-applet >/dev/null && nm-applet &
command -v xss-lock >/dev/null && xss-lock --transfer-sleep-lock -- i3lock -n -c 000000 &
command -v slstatus >/dev/null && slstatus &
picom --daemon
exec dwm
