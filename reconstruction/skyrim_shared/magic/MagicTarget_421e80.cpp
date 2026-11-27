// Source exposure: binary-analysis (pinned-image observations; community-generated name map).
// Code origin: original handwritten resistance calculation
// Adapted bodies: none
// 0x421e80 MagicTarget::GetResistance
#include "MagicTarget_421e80.h"

// Combine the two percentage resistances into the remaining effect fraction.
float MagicTarget::GetResistance(float magicResistance, float elementalResistance)
{
    if (magicResistance >= 100.0f || elementalResistance >= 100.0f)
        return 0.0f;
    const float magicFraction = magicResistance * 0.01f;
    const float elementalFraction = elementalResistance * 0.01f;
    return 1.0f - (elementalFraction * (1.0f - magicFraction) + magicFraction);
}
