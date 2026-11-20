// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSSoundOutput; size 0x40
#pragma once

#include "BSISoundOutputModel.h"
#include "TESForm.h"
#include "Type_bad13f76.h"
struct DynamicAttenuationCharacteristics;
struct SpeakerArrays;
struct BGSSoundOutput {
    TESForm _base;
    BSISoundOutputModel _base_BSISoundOutputModel;
    unsigned char data_raw[4];
    Type_bad13f76 type;
    DynamicAttenuationCharacteristics* attenuation;
    SpeakerArrays* speakerOutputs;
};
static_assert(sizeof(BGSSoundOutput) == 64, "BGSSoundOutput layout differs from the PDB");
