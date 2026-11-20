// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CreatedMagicItemData; size 0x10
#pragma once

struct MagicItem_34516af4;
struct CreatedMagicItemData {
    MagicItem_34516af4* magicItem;
    unsigned int refCount;
    unsigned int pad0C;
};
static_assert(sizeof(CreatedMagicItemData) == 16, "CreatedMagicItemData layout differs from the PDB");
