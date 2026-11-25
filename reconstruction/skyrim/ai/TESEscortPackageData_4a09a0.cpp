// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESEscortPackageData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~TESEscortPackageData: GUESS(low); provisional member name
// 0x4a09a0 TESEscortPackageData::~TESEscortPackageData
// CI hash: 0x4a09a0 ??1TESEscortPackageData@@UEAA@XZ
#include "TESEscortPackageData_4a09a0.h"

// Guess: Destroy the owned package state before completing base teardown.
 TESEscortPackageData::~TESEscortPackageData()
{
    if (owned) { delete owned; }
}
