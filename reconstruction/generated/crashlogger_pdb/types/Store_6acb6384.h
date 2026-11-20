// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Store; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "IStore.h"
struct Stream;
struct Store_6acb6384 {
    IStore _base;
    unsigned long long unk20;
    Stream* stream;
    BSFixedString_char_83b572b4 relPath;
    bool hasOpenFile;
    bool fileIsGood;
    unsigned short pad3A;
    unsigned int pad3C;
};
static_assert(sizeof(Store_6acb6384) == 64, "Store_6acb6384 layout differs from the PDB");
