// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProperty; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkpPropertyValue_c597e019.h"
struct hkpProperty {
    unsigned int key;
    unsigned int alignmentPadding;
    hkpPropertyValue_c597e019 value;
};
static_assert(sizeof(hkpProperty) == 16, "hkpProperty layout differs from the PDB");
