// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSceneAction; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "Flag_d5bcd2af.h"
struct BGSSceneAction_vtbl;
struct BGSSceneAction_eb088615 {
    BGSSceneAction_vtbl* __vftable;
    unsigned int actorID;
    unsigned short startPhase;
    unsigned short endPhase;
    Flag_d5bcd2af flags;
    unsigned char unk14;
    unsigned char unk15;
    unsigned short unk16;
    unsigned int index;
    unsigned int unk1C;
};
static_assert(sizeof(BGSSceneAction_eb088615) == 32, "BGSSceneAction_eb088615 layout differs from the PDB");
