// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ConsoleNativeUIMenu; size 0x38
#pragma once

#include "IMenu_09c1ffe2.h"
struct ConsoleNativeUIMenu {
    IMenu_09c1ffe2 _base;
    unsigned char unk30;
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(ConsoleNativeUIMenu) == 56, "ConsoleNativeUIMenu layout differs from the PDB");
