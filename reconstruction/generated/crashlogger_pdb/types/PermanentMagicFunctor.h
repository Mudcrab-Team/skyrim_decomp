// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PermanentMagicFunctor; size 0x18
#pragma once

struct Actor_b2630b95;
struct MagicCaster;
struct PermanentMagicFunctor {
    MagicCaster* caster;
    Actor_b2630b95* actor;
    unsigned char isSpellType;
    unsigned char isNotSpellType;
    unsigned char flags;
    unsigned char pad13;
    unsigned int pad14;
};
static_assert(sizeof(PermanentMagicFunctor) == 24, "PermanentMagicFunctor layout differs from the PDB");
