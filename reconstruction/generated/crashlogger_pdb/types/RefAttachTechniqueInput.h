// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RefAttachTechniqueInput; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct RefAttachTechniqueInput__VFTable;
struct TESObjectREFR;
struct RefAttachTechniqueInput {
    RefAttachTechniqueInput__VFTable* vftable_RefAttachTechniqueInput_0;
    TESObjectREFR* actor;
    unsigned char undefined_10[56];
};
static_assert(sizeof(RefAttachTechniqueInput) == 72, "RefAttachTechniqueInput layout differs from the PDB");
