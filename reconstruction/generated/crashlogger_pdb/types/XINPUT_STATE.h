// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: XINPUT_STATE; size 0x10
#pragma once

#include "XINPUT_GAMEPAD.h"
struct XINPUT_STATE {
    unsigned int packetNumber;
    XINPUT_GAMEPAD gamepad;
};
static_assert(sizeof(XINPUT_STATE) == 16, "XINPUT_STATE layout differs from the PDB");
