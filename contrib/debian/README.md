
Debian
====================
This directory contains files used to package qoinzd/qoinz-qt
for Debian-based Linux systems. If you compile qoinzd/qoinz-qt yourself, there are some useful files here.

## qoinz: URI support ##


qoinz-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install qoinz-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your qoinzqt binary to `/usr/bin`
and the `../../share/pixmaps/qoinz128.png` to `/usr/share/pixmaps`

qoinz-qt.protocol (KDE)
