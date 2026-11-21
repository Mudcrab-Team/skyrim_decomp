// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RefAttachTechniqueInput; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "AttachTechniqueInput.h"
#include "BSFixedString_char_83b572b4.h"
struct TESObjectREFR_b225f218;
struct TESRace;
struct bhkWorld_a655538a;
struct RefAttachTechniqueInput_0f9ae65d {
    AttachTechniqueInput _base;
    TESObjectREFR_b225f218* actor;
    TESRace* actorRace;
    bhkWorld_a655538a* physicsWorld;
    unsigned int collisionFilter;
    unsigned int unk3C;
    BSFixedString_char_83b572b4 nodeName;
};
static_assert(sizeof(RefAttachTechniqueInput_0f9ae65d) == 72, "RefAttachTechniqueInput_0f9ae65d layout differs from the PDB");
