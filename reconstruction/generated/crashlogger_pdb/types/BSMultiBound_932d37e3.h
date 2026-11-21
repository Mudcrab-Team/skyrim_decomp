// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiBound; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "NiObject.h"
#include "NiPointer_RE__BSMultiBoundShape_c9031172.h"
struct BSMultiBound_932d37e3 {
    NiObject _base;
    unsigned int unk10;
    unsigned int pad14;
    NiPointer_RE__BSMultiBoundShape_c9031172 data;
};
static_assert(sizeof(BSMultiBound_932d37e3) == 32, "BSMultiBound_932d37e3 layout differs from the PDB");
