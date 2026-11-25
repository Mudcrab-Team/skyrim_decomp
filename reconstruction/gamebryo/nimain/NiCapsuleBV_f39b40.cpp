// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiCapsuleBV: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionf39b40: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xf39b40 NiCapsuleBV::Functionf39b40
// CI hash: 0xf39b40 ?Functionf39b40@NiCapsuleBV@@QEAAXXZ
#include "NiCapsuleBV_f39b40.h"

// Guess: Derive the capsule support segment from its axis and endpoint radii.
void NiCapsuleBV::Functionf39b40()
{
    start = direction;
    start.Scale(radiusEnd - radiusStart);
    start.Add(center);
    extent = direction;
    extent.Scale(2.0f * (radiusStart - radiusEnd));
}
