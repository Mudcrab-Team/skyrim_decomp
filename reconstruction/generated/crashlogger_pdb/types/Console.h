// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Console; size 0x60
#pragma once

#include "IMenu_09c1ffe2.h"
struct Console {
    IMenu_09c1ffe2 _base;
    void* opcode;
    unsigned long long unk38;
    unsigned long long unk40;
    unsigned int pad48;
    unsigned char pad4c;
    bool showAchievementWarning;
    bool ctrlKeyHeld;
    unsigned char pad4f;
    unsigned long long unk48;
    unsigned long long unk50;
};
static_assert(sizeof(Console) == 96, "Console layout differs from the PDB");
