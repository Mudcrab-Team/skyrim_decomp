// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSSystemFileStorage; size 0x38
#pragma once

#include "Attributes.h"
#include "BSStorage.h"
struct BSSystemFileStorage {
    BSStorage _base;
    Attributes attributes;
    bool unk30;
    bool unk31;
    bool goodForRead;
    unsigned char pad33;
    unsigned int pad34;
};
static_assert(sizeof(BSSystemFileStorage) == 56, "BSSystemFileStorage layout differs from the PDB");
