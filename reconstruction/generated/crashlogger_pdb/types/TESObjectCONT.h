// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectCONT; size 0xd0
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSOpenCloseForm.h"
#include "TESBoundAnimObject.h"
#include "TESContainer.h"
#include "TESFullName.h"
#include "TESMagicCasterForm.h"
#include "TESMagicTargetForm.h"
#include "TESModelTextureSwap_014aa4ed.h"
#include "TESWeightForm.h"
struct BGSSoundDescriptorForm;
struct TESObjectCONT {
    TESBoundAnimObject _base;
    TESContainer _base_TESContainer;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    TESWeightForm _base_TESWeightForm;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSOpenCloseForm _base_BGSOpenCloseForm;
    TESMagicCasterForm _base_TESMagicCasterForm;
    TESMagicTargetForm _base_TESMagicTargetForm;
    unsigned short padBA;
    unsigned int padBC;
    BGSSoundDescriptorForm* openSound;
    BGSSoundDescriptorForm* closeSound;
};
static_assert(sizeof(TESObjectCONT) == 208, "TESObjectCONT layout differs from the PDB");
