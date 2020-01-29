#!/bin/bash
# create multiresolution windows icon
#mainnet
ICON_SRC=../../src/qt/res/icons/qoinz.png
ICON_DST=../../src/qt/res/icons/qoinz.ico
convert ${ICON_SRC} -resize 16x16 qoinz-16.png
convert ${ICON_SRC} -resize 32x32 qoinz-32.png
convert ${ICON_SRC} -resize 48x48 qoinz-48.png
convert qoinz-16.png qoinz-32.png qoinz-48.png ${ICON_DST}
#testnet
ICON_SRC=../../src/qt/res/icons/qoinz_testnet.png
ICON_DST=../../src/qt/res/icons/qoinz_testnet.ico
convert ${ICON_SRC} -resize 16x16 qoinz-16.png
convert ${ICON_SRC} -resize 32x32 qoinz-32.png
convert ${ICON_SRC} -resize 48x48 qoinz-48.png
convert qoinz-16.png qoinz-32.png qoinz-48.png ${ICON_DST}
rm qoinz-16.png qoinz-32.png qoinz-48.png
