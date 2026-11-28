// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x856a80 CombatState::BoostConfidence
#include "CombatState_856a80.h"

// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool CombatState::BoostConfidence()
{
    if (confidenceLevel < 4 && GetConfidenceLevel(confidenceLevel) < gConfidenceThreshold) {
        ++confidenceLevel;
        return true;
    }
    return false;
}
