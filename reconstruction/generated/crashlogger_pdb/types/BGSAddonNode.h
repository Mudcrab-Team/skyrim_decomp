// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAddonNode; size 0x80
#pragma once

#include "ADDON_DATA.h"
#include "TESBoundObject_fc790793.h"
#include "TESModelTextureSwap_014aa4ed.h"
struct BGSSoundDescriptorForm;
struct BGSAddonNode {
    TESBoundObject_fc790793 _base;
    TESModelTextureSwap_014aa4ed _base_TESModelTextureSwap;
    unsigned int index;
    unsigned int pad6C;
    BGSSoundDescriptorForm* sound;
    ADDON_DATA data;
    unsigned int pad7C;
};
static_assert(sizeof(BGSAddonNode) == 128, "BGSAddonNode layout differs from the PDB");
