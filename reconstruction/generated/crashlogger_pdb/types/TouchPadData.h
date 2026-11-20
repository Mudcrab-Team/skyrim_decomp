// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TouchPadData; size 0x18
#pragma once
struct TouchPadData {
    unsigned char touchNum;
    unsigned char pad01[3];
    unsigned int pad04;
    unsigned char touch_raw[16];
};
static_assert(sizeof(TouchPadData) == 24, "TouchPadData layout differs from the PDB");
