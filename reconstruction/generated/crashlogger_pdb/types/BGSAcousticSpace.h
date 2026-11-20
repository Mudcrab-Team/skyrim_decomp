// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSAcousticSpace; size 0x48
#pragma once

#include "TESBoundObject_fc790793.h"
struct BGSReverbParameters;
struct BGSSoundDescriptorForm;
struct TESRegion;
struct BGSAcousticSpace {
    TESBoundObject_fc790793 _base;
    BGSSoundDescriptorForm* loopingSound;
    TESRegion* soundRegion;
    BGSReverbParameters* reverbType;
};
static_assert(sizeof(BGSAcousticSpace) == 72, "BGSAcousticSpace layout differs from the PDB");
