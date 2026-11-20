// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundDescriptor; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BSISoundDescriptor.h"
struct BGSSoundCategory_10dfc5b0;
struct BGSSoundDescriptor_3b5294f3 {
    BSISoundDescriptor _base;
    BGSSoundCategory_10dfc5b0* category;
    unsigned int alternateSoundFormID;
    unsigned int pad14;
};
static_assert(sizeof(BGSSoundDescriptor_3b5294f3) == 24, "BGSSoundDescriptor_3b5294f3 layout differs from the PDB");
