// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSNote; size 0xb8
#pragma once

#include "BGSPickupPutdownSounds.h"
#include "BSSimpleList_RE__TESQuest_6f60d863.h"
#include "TESBoundObject.h"
#include "TESFullName_88f61e2a.h"
#include "TESIcon.h"
#include "TESModel.h"
struct TESActorBase;
struct TESTopic;
struct BGSNote {
    TESBoundObject _base;
    TESModel _base_TESModel;
    TESFullName_88f61e2a _base_TESFullName;
    TESIcon _base_TESIcon;
    BGSPickupPutdownSounds _base_BGSPickupPutdownSounds;
    TESTopic* unk90;
    TESActorBase* unk98;
    BSSimpleList_RE__TESQuest_6f60d863 unkA0;
    unsigned long long unkB0;
};
static_assert(sizeof(BGSNote) == 184, "BGSNote layout differs from the PDB");
