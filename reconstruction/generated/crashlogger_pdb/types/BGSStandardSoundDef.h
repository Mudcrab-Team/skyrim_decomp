// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStandardSoundDef; size 0x58
#pragma once

#include "BGSSoundDescriptor_3b5294f3.h"
#include "BSTArray_RE__BSResource__ID_26021abb.h"
#include "LengthCharacteristics.h"
#include "SoundPlaybackCharacteristics.h"
struct BGSSoundOutput;
struct TESCondition_4d3cdc88;
struct BGSStandardSoundDef {
    BGSSoundDescriptor_3b5294f3 _base;
    BSTArray_RE__BSResource__ID_26021abb soundFiles;
    SoundPlaybackCharacteristics soundCharacteristics;
    TESCondition_4d3cdc88* conditions;
    BGSSoundOutput* outputModel;
    LengthCharacteristics lengthCharacteristics;
    int unk54;
};
static_assert(sizeof(BGSStandardSoundDef) == 88, "BGSStandardSoundDef layout differs from the PDB");
