// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// MagicItem: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1502e0: GUESS(low); provisional member name
// 0x1502e0 MagicItem::Function1502e0
// CI hash: 0x1502e0 ?Function1502e0@MagicItem@@QEAA_NXZ
#include "MagicItem_1502e0.h"

// Guess: Test whether the casting category lies outside a three-value range.
bool MagicItem::Function1502e0()
{
    switch (GetCastingType()) {
    case 2: case 3: case 4: return false;
    default: return true;
    }
}
