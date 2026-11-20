// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundDescriptor; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSISoundDescriptor_cac04df2.h"
struct BGSSoundCategory;
struct BGSSoundDescriptor {
    BSISoundDescriptor_cac04df2 _base;
    BGSSoundCategory* category;
    unsigned int alternateSoundFormID;
    unsigned int pad14;
};
static_assert(sizeof(BGSSoundDescriptor) == 24, "BGSSoundDescriptor layout differs from the PDB");
