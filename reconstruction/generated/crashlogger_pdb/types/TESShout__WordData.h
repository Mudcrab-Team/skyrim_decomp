// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESShout__WordData; size 0x18
#pragma once

struct SpellItem;
struct TESWordOfPower;
struct TESShout__WordData {
    TESWordOfPower* Word_0;
    SpellItem* Spell_8;
    float RecoveryTime_10;
    char _pad_14[4];
};
static_assert(sizeof(TESShout__WordData) == 24, "TESShout__WordData layout differs from the PDB");
