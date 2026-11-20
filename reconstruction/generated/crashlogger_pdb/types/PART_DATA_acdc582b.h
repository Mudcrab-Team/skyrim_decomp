// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PART_DATA; size 0x78
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__ActorValue_unsigned_char_96d40019.h"
#include "EnumSet_RE__BGSBodyPartDefs__LIMB_ENUMS__LIMB_ENUM_unsigned_char_be470b5b.h"
#include "EnumSet_RE__PART_DATA__Flag_unsigned_char_b221677f.h"
#include "NiPoint3_a7124070.h"
struct BGSDebris_f2fddb01;
struct BGSExplosion;
struct BGSImpactDataSet;
struct PART_DATA_acdc582b {
    float damageMult;
    EnumSet_RE__PART_DATA__Flag_unsigned_char_b221677f flags;
    EnumSet_RE__BGSBodyPartDefs__LIMB_ENUMS__LIMB_ENUM_unsigned_char_be470b5b type;
    unsigned char healthPercent;
    EnumSet_RE__ActorValue_unsigned_char_96d40019 actorValue;
    unsigned char toHitChance;
    unsigned char explosionChance;
    unsigned char explosionGenericDebrisCount;
    unsigned char pad0B;
    unsigned int pad0C;
    BGSDebris_f2fddb01* explosionGenericDebris;
    BGSExplosion* explosion;
    float trackingMaxAngle;
    float explosionGenericDebrisScale;
    unsigned char dismemberGenericDebrisCount;
    unsigned char unk29;
    unsigned short unk2A;
    unsigned int unk2C;
    BGSDebris_f2fddb01* dismemberGenericDebris;
    BGSExplosion* dismemberExplosion;
    float dismemberGenericDebrisScale;
    NiPoint3_a7124070 goreTranslate;
    NiPoint3_a7124070 goreRotate;
    unsigned int pad5C;
    BGSImpactDataSet* dismemberImpactDataSet;
    BGSImpactDataSet* explosionImpactDataSet;
    unsigned char dismemberDecalCount;
    unsigned char explosionDecalCount;
    unsigned short pad72;
    float explosionSpecialDebrisScale;
};
static_assert(sizeof(PART_DATA_acdc582b) == 120, "PART_DATA_acdc582b layout differs from the PDB");
