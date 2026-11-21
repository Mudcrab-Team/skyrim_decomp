// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CLASS_DATA; size 0x24
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AttributeWeights.h"
#include "SkillWeights.h"
struct CLASS_DATA {
    unsigned int unk00;
    unsigned char teaches;  // Skill in the PDB is wider than this slot
    unsigned char maximumTrainingLevel;
    SkillWeights skillWeights;
    float bleedoutDefault;
    unsigned int voicePoints;
    AttributeWeights attributeWeights;
    unsigned char pad23;
};
static_assert(sizeof(CLASS_DATA) == 36, "CLASS_DATA layout differs from the PDB");
