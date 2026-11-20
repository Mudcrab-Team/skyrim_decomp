// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: RACE_DATA; size 0xa4
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BIPED_OBJECT.h"
#include "Flag2.h"
#include "Flag_a4a94b8a.h"
#include "NiPoint3.h"
#include "RACE_SIZE.h"
struct RACE_DATA {
    unsigned char skillBoosts_raw[14];
    unsigned short pad0E;
    float height[2];
    float weight[2];
    Flag_a4a94b8a flags;
    float startingHealth;
    float startingMagicka;
    float startingStamina;
    float baseCarryWeight;
    float baseMass;
    float accelerate;
    float decelerate;
    RACE_SIZE raceSize;
    BIPED_OBJECT headObject;
    BIPED_OBJECT hairObject;
    float injuredHealthPercent;
    BIPED_OBJECT shieldObject;
    float healthRegen;
    float magickaRegen;
    float staminaRegen;
    float unarmedDamage;
    float unarmedReach;
    BIPED_OBJECT bodyObject;
    float aimAngleTolerance;
    float flightRadius;
    float angleAccelerate;
    float angleTolerance;
    Flag2 flags2;
    NiPoint3 mountOffset;
    NiPoint3 dismountOffset;
    NiPoint3 mountCameraOffset;
};
static_assert(sizeof(RACE_DATA) == 164, "RACE_DATA layout differs from the PDB");
