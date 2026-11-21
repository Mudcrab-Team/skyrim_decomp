// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BoneEntry; size 0x80
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "NiTransform.h"
struct NiAVObject;
struct BoneEntry {
    NiTransform local;
    NiTransform world;
    short parentIndex;
    short unk6A;
    unsigned short childCount;
    short nextSiblingIndex;
    NiAVObject* node;
    BSFixedString_char_83b572b4 nodeName;
};
static_assert(sizeof(BoneEntry) == 128, "BoneEntry layout differs from the PDB");
