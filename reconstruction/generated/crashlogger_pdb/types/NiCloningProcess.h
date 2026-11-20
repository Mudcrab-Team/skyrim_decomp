// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiCloningProcess; size 0x78
#pragma once

#include "BSTScatterTable_RE__BSCRC32_RE__NiObject_std__equal_to_RE__NiObject_RE__BSTScatterTable_23786ce0.h"
#include "BSTScatterTable_RE__BSCRC32_RE__NiObject_std__equal_to_RE__NiObject_RE__BSTScatterTable_4330724c.h"
struct NiCloningProcess {
    BSTScatterTable_RE__BSCRC32_RE__NiObject_std__equal_to_RE__NiObject_RE__BSTScatterTable_23786ce0 cloneMap;
    BSTScatterTable_RE__BSCRC32_RE__NiObject_std__equal_to_RE__NiObject_RE__BSTScatterTable_4330724c processMap;
    unsigned int copyType;
    unsigned char appendChar;
    unsigned char undefined_65[1];
    unsigned short pad65;
    unsigned char scale_raw[16];
};
static_assert(sizeof(NiCloningProcess) == 120, "NiCloningProcess layout differs from the PDB");
