// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PART_DATA; size 0x78
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "NiPoint3.h"
struct BGSDebris;
struct BGSExplosion_c355258c;
struct BGSImpactDataSet_e1a4fffc;
struct PART_DATA {
    float damageMult;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned char type_raw;
    unsigned char healthPercent;
    unsigned char actorValue;  // ActorValue in the PDB is wider than this slot
    unsigned char toHitChance;
    unsigned char explosionChance;
    unsigned char explosionGenericDebrisCount;
    unsigned char pad0B;
    unsigned int pad0C;
    BGSDebris* explosionGenericDebris;
    BGSExplosion_c355258c* explosion;
    float trackingMaxAngle;
    float explosionGenericDebrisScale;
    unsigned char dismemberGenericDebrisCount;
    unsigned char unk29;
    unsigned short unk2A;
    unsigned int unk2C;
    BGSDebris* dismemberGenericDebris;
    BGSExplosion_c355258c* dismemberExplosion;
    float dismemberGenericDebrisScale;
    NiPoint3 goreTranslate;
    NiPoint3 goreRotate;
    unsigned int pad5C;
    BGSImpactDataSet_e1a4fffc* dismemberImpactDataSet;
    BGSImpactDataSet_e1a4fffc* explosionImpactDataSet;
    unsigned char dismemberDecalCount;
    unsigned char explosionDecalCount;
    unsigned short pad72;
    float explosionSpecialDebrisScale;
};
static_assert(sizeof(PART_DATA) == 120, "PART_DATA layout differs from the PDB");
