// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneAction; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Flag_a4a94b8a.h"
struct BGSSceneAction_vtbl_aa216f6f;
struct BGSSceneAction {
    BGSSceneAction_vtbl_aa216f6f* __vftable;
    unsigned int actorID;
    unsigned short startPhase;
    unsigned short endPhase;
    Flag_a4a94b8a flags;
    unsigned char unk14;
    unsigned char unk15;
    unsigned short unk16;
    unsigned int index;
    unsigned int unk1C;
};
static_assert(sizeof(BGSSceneAction) == 32, "BGSSceneAction layout differs from the PDB");
