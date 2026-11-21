// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MessageBoxMenu; size 0x38
#pragma once

#include "IMenu_09c1ffe2.h"
struct MessageBoxMenu {
    IMenu_09c1ffe2 _base;
    bool isPopulated;
    unsigned char pad31;
    unsigned short pad32;
    unsigned int pad34;
};
static_assert(sizeof(MessageBoxMenu) == 56, "MessageBoxMenu layout differs from the PDB");
