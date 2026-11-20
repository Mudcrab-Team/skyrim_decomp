// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESSpellList__Data; size 0x28
#pragma once

struct SpellItem;
struct TESLevSpell;
struct TESShout;
struct TESSpellList__Data {
    TESLevSpell** LeveledSpells_8;
    int NumSpells_18;
    int NumLeveledSpells_1C;
    int NumShouts_20;
    char _pad_24[4];
    SpellItem** Spells_0;
    TESShout** Shouts_10;
};
static_assert(sizeof(TESSpellList__Data) == 40, "TESSpellList__Data layout differs from the PDB");
