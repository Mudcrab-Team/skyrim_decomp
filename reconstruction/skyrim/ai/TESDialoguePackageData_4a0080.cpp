// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESDialoguePackageData: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~TESDialoguePackageData: GUESS(low); provisional member name
// 0x4a0080 TESDialoguePackageData::~TESDialoguePackageData
// CI hash: 0x4a0080 ??1TESDialoguePackageData@@UEAA@XZ
#include "TESDialoguePackageData_4a0080.h"

// Guess: Destroy the owned package state before completing base teardown.
 TESDialoguePackageData::~TESDialoguePackageData()
{
    if (owned) { delete owned; }
}
