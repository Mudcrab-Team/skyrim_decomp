// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PACKAGE_DATA; size 0xc
#pragma once

#include "GeneralFlag.h"
struct PACKAGE_DATA {
    GeneralFlag packFlags;
    unsigned char packType;  // PACKAGE_TYPE in the PDB is wider than this slot
    unsigned char interruptOverrideType;  // PACK_INTERRUPT_TARGET in the PDB is wider than this slot
    unsigned char maxSpeed;  // PreferredSpeed in the PDB is wider than this slot
    unsigned char pad7;
    unsigned short foBehaviorFlags;  // InterruptFlag in the PDB is wider than this slot
    unsigned short packageSpecificFlags;
};
static_assert(sizeof(PACKAGE_DATA) == 12, "PACKAGE_DATA layout differs from the PDB");
