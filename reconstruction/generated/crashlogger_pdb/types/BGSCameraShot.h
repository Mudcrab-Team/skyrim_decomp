// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSCameraShot; size 0xc0
#pragma once

#include "CAMERA_SHOT_DATA.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
#include "TESForm.h"
#include "TESImageSpaceModifiableForm.h"
#include "TESModel_c52655e4.h"
struct NiAVObject;
struct BGSCameraShot {
    TESForm _base;
    TESModel_c52655e4 _base_TESModel;
    TESImageSpaceModifiableForm _base_TESImageSpaceModifiableForm;
    CAMERA_SHOT_DATA data;
    unsigned int pad84;
    NiAVObject* locationNode;
    NiAVObject* targetNode;
    unsigned int unk98;
    unsigned int unk9C;
    NiPointer_RE__NiNode_28171d5b cameraNode;
    NiPointer_RE__NiAVObject_9e3aa701 targetFadeNode;
    unsigned char unkB0;
    bool unkB1;
    unsigned short padB2;
    unsigned int padB4;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 cameraHandle;
};
static_assert(sizeof(BGSCameraShot) == 192, "BGSCameraShot layout differs from the PDB");
