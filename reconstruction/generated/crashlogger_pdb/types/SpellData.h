// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpellData; size 0x28
#pragma once

struct SpellItem_847bf892;
struct TESLevSpell_3f8ca670;
struct TESShout_ea437759;
struct SpellData {
    SpellItem_847bf892** spells;
    TESLevSpell_3f8ca670** levSpells;
    TESShout_ea437759** shouts;
    unsigned int numSpells;
    unsigned int numlevSpells;
    unsigned int numShouts;
    unsigned int pad24;
};
static_assert(sizeof(SpellData) == 40, "SpellData layout differs from the PDB");
