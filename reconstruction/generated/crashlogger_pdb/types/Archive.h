// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Archive; size 0x230
#pragma once

#include "BSArchive.h"
#include "BSFile.h"
#include "NiRefObject_f24a9221.h"
struct Archive {
    BSFile _base;
    NiRefObject_f24a9221 _base_NiRefObject;
    BSArchive _base_BSArchive;
    unsigned long long unk1C0;
    unsigned long long unk1C8;
    unsigned long long unk1D0;
    unsigned long long unk1D8;
    unsigned long long unk1E0;
    unsigned long long unk1E8;
    unsigned long long unk1F0;
    unsigned long long unk1F8;
    unsigned long long unk200;
    unsigned long long unk208;
    unsigned long long unk210;
    unsigned long long unk218;
    unsigned long long unk220;
    unsigned long long unk228;
};
static_assert(sizeof(Archive) == 560, "Archive layout differs from the PDB");
