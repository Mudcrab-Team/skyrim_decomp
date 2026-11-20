// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectACTI; size 0xc8
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSOpenCloseForm.h"
#include "TESBoundAnimObject.h"
#include "TESFullName.h"
#include "TESMagicTargetForm.h"
#include "TESModelTextureSwap_014aa4ed.h"
struct BGSSoundDescriptorForm;
struct TESWaterForm_2ffdeaeb;
struct TESObjectACTI_e432b98e {
    TESBoundAnimObject _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSOpenCloseForm _base_BGSOpenCloseForm;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    TESMagicTargetForm _base_TESMagicTargetForm;
    unsigned char undefined_a9[7];
    BGSSoundDescriptorForm* soundActivate;
    TESWaterForm_2ffdeaeb* waterForm;
    unsigned short flags;  // ActiFlags in the PDB is wider than this slot
    unsigned short padC2;
    unsigned int padC4;
};
static_assert(sizeof(TESObjectACTI_e432b98e) == 200, "TESObjectACTI_e432b98e layout differs from the PDB");
