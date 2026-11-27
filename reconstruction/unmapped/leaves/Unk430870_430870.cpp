// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk430870: STANDIN GUESS(low)
// Unk430870::Function430870: GUESS(low)
// Unk430870::storedValue: GUESS(low)
// 0x430870 Unk430870::Function430870
#include "Unk430870_430870.h"

// Read or update the stored values.
bool Unk430870::Function430870(float value)
{
    if (storedValue != value) {
        storedValue = value;
        return true;
    }
    return false;
}
