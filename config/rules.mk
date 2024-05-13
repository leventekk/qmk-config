CONVERT_TO = promicro_rp2040

BOOTMAGIC_ENABLE = yes

FORCE_NKRO = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
SPLIT_KEYBOARD = yes

OLED_ENABLE = yes
LTO_ENABLE = yes
WPM_ENABLE = yes

AUDIO_ENABLE = no           # Audio output on port C6
MIDI_ENABLE = no            # MIDI controls
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
EXTRAFLAGS += -flto
