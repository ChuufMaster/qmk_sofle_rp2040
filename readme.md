# Lily58 Keyboard with RP2040 Microcontroller

Put RP2040 microcontroller into bootloader mode before flashing firmware. 

Example command for build firmware with default keymap and then flash the left half:

    qmk flash -kb lily58_rp2040 -km default -bl uf2-split-left

Example command for build firmware with default keymap and then flash the right half:

    qmk flash -kb lily58_rp2040 -km default -bl uf2-split-right
