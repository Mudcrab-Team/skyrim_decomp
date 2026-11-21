// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RACE_DATA; size 0xa4
// one of 2 different PDB types sharing this name
#pragma once

#include "EnumSet_RE__BIPED_OBJECTS__BIPED_OBJECT_unsigned_int_aa02c020.h"
#include "EnumSet_RE__RACE_DATA__Flag2_unsigned_int_e473a7f4.h"
#include "EnumSet_RE__RACE_DATA__Flag_unsigned_int_c2a5903d.h"
#include "EnumSet_RE__RACE_SIZE_unsigned_int_078f3cbc.h"
#include "NiPoint3_a7124070.h"
struct RACE_DATA_45756db8 {
    unsigned char skillBoosts_raw[14];
    unsigned short pad0E;
    float height[2];
    float weight[2];
    EnumSet_RE__RACE_DATA__Flag_unsigned_int_c2a5903d flags;
    float startingHealth;
    float startingMagicka;
    float startingStamina;
    float baseCarryWeight;
    float baseMass;
    float accelerate;
    float decelerate;
    EnumSet_RE__RACE_SIZE_unsigned_int_078f3cbc raceSize;
    EnumSet_RE__BIPED_OBJECTS__BIPED_OBJECT_unsigned_int_aa02c020 headObject;
    EnumSet_RE__BIPED_OBJECTS__BIPED_OBJECT_unsigned_int_aa02c020 hairObject;
    float injuredHealthPercent;
    EnumSet_RE__BIPED_OBJECTS__BIPED_OBJECT_unsigned_int_aa02c020 shieldObject;
    float healthRegen;
    float magickaRegen;
    float staminaRegen;
    float unarmedDamage;
    float unarmedReach;
    EnumSet_RE__BIPED_OBJECTS__BIPED_OBJECT_unsigned_int_aa02c020 bodyObject;
    float aimAngleTolerance;
    float flightRadius;
    float angleAccelerate;
    float angleTolerance;
    EnumSet_RE__RACE_DATA__Flag2_unsigned_int_e473a7f4 flags2;
    NiPoint3_a7124070 mountOffset;
    NiPoint3_a7124070 dismountOffset;
    NiPoint3_a7124070 mountCameraOffset;
};
static_assert(sizeof(RACE_DATA_45756db8) == 164, "RACE_DATA_45756db8 layout differs from the PDB");
