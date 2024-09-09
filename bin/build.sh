#!/usr/bin/env bash

set -eu

PWD=$(pwd)
TIMESTAMP="${TIMESTAMP:-$(date -u +"%Y%m%d%H%M")}"
KEYMAP_NAME="${KEYMAP_NAME:-default}"
DEVICE="${DEVICE:-promicro_rp2040}"
OUTPUT_FILE="crkbd_rev1_${KEYMAP_NAME}_${DEVICE}.uf2"

echo "Building firmware for keymap: ${KEYMAP_NAME} - ${DEVICE}"

ls -la "$PWD/qmk_firmware/keyboards/crkbd/keymaps/crkbd_custom"

qmk compile -kb crkbd/rev1 -j 0 -km "$KEYMAP_NAME" -e CONVERT_TO="$DEVICE" -e DEVICE="$DEVICE"

cp "$PWD/qmk_firmware/$OUTPUT_FILE" "./firmware/${TIMESTAMP}-${OUTPUT_FILE}"
