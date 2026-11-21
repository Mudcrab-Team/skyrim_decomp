// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSMultiBound; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiObject_de5bc370.h"
#include "NiPointer_RE__BSMultiBoundShape_c9031172.h"
struct BSMultiBound {
    NiObject_de5bc370 _base;
    unsigned int unk10;
    unsigned int pad14;
    NiPointer_RE__BSMultiBoundShape_c9031172 data;
};
static_assert(sizeof(BSMultiBound) == 32, "BSMultiBound layout differs from the PDB");
