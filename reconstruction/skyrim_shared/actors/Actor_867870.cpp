// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: CombatUtilities_ComputeProjectileTime.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout/ai/combat/combatutilities.cpp:93
// 0x867870 CombatUtilities_ComputeProjectileTime
#include "Actor_867870.h"

float CombatUtilities_ComputeProjectileTime(float afNumerator, float afInput, float c)
{
    return afNumerator / (NiCos(afInput) * c);
}
