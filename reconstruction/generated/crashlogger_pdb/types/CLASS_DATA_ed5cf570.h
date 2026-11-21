// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: CLASS_DATA; size 0x24
// one of 2 different PDB types sharing this name
#pragma once

#include "AttributeWeights.h"
#include "EnumSet_RE__CLASS_DATA__Skill_unsigned_char_482ea3f8.h"
#include "SkillWeights.h"
struct CLASS_DATA_ed5cf570 {
    unsigned int unk00;
    EnumSet_RE__CLASS_DATA__Skill_unsigned_char_482ea3f8 teaches;
    unsigned char maximumTrainingLevel;
    SkillWeights skillWeights;
    float bleedoutDefault;
    unsigned int voicePoints;
    AttributeWeights attributeWeights;
    unsigned char pad23;
};
static_assert(sizeof(CLASS_DATA_ed5cf570) == 36, "CLASS_DATA_ed5cf570 layout differs from the PDB");
