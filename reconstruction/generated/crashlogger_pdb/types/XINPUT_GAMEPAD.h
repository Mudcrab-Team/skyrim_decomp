// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: XINPUT_GAMEPAD; size 0xc
#pragma once
struct XINPUT_GAMEPAD {
    unsigned short buttons;
    unsigned char leftTrigger;
    unsigned char rightTrigger;
    short thumbLX;
    short thumbLY;
    short thumbRX;
    short thumbRY;
};
static_assert(sizeof(XINPUT_GAMEPAD) == 12, "XINPUT_GAMEPAD layout differs from the PDB");
