// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectDOOR; size 0xd0
#pragma once

#include "BGSDestructibleObjectForm.h"
#include "BGSOpenCloseForm.h"
#include "BSTArray_RE__TESForm_7f041170.h"
#include "TESBoundAnimObject.h"
#include "TESFullName.h"
#include "TESModelTextureSwap_014aa4ed.h"
struct BGSSoundDescriptorForm;
struct TESObjectDOOR {
    TESBoundAnimObject _base;
    TESFullName _base_TESFullName;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSOpenCloseForm _base_BGSOpenCloseForm;
    unsigned long long unk90;
    BGSSoundDescriptorForm* openSound;
    BGSSoundDescriptorForm* closeSound;
    BGSSoundDescriptorForm* loopSound;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char padB1;
    unsigned short padB2;
    unsigned int padB4;
    BSTArray_RE__TESForm_7f041170 randomTeleports;
};
static_assert(sizeof(TESObjectDOOR) == 208, "TESObjectDOOR layout differs from the PDB");
