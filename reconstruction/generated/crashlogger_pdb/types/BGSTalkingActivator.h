// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSTalkingActivator; size 0xd8
#pragma once

#include "TESObjectACTI_e432b98e.h"
struct BGSVoiceType;
struct TESObjectREFR_b225f218;
struct BGSTalkingActivator {
    TESObjectACTI_e432b98e _base;
    TESObjectREFR_b225f218* tempRef;
    BGSVoiceType* voiceType;
};
static_assert(sizeof(BGSTalkingActivator) == 216, "BGSTalkingActivator layout differs from the PDB");
