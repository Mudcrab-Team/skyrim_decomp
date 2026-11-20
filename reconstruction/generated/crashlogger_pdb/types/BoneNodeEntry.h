// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BoneNodeEntry; size 0x10
#pragma once

struct NiNode;
struct BoneNodeEntry {
    NiNode* node;
    unsigned int unk08;
    unsigned int unk0C;
};
static_assert(sizeof(BoneNodeEntry) == 16, "BoneNodeEntry layout differs from the PDB");
