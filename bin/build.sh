#!/usr/bin/env bash

set -eu

PWD=$(pwd)
TIMESTAMP="${TIMESTAMP:-$(date -u +"%Y%m%d%H%M")}"
KEYMAP_NAME="${KEYMAP_NAME:-default}"
OUTPUT_FILE="crkbd_rev1_${KEYMAP_NAME}_promicro_rp2040.uf2"

echo "Building firmware for keymap: ${KEYMAP_NAME}"

ls -la "$PWD/qmk_firmware/keyboards/crkbd/keymaps/crkbd_custom"

qmk compile -kb crkbd/rev1 -km "$KEYMAP_NAME" -e CONVERT_TO=promicro_rp2040

cp "$PWD/qmk_firmware/$OUTPUT_FILE" "./firmware/${TIMESTAMP}-${OUTPUT_FILE}"
