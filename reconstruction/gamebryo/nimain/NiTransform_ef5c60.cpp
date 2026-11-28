// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xef5c60 NiTransform::IsZero
#include "NiTransform_ef5c60.h"

#include <cmath>

// "Zero" in the community name means the null transform: identity rotation, zero translation and
// unit scale within epsilon.
bool NiTransform::IsZero() const
{
    return rotate == gIdentityMatrix &&
           translate == gZeroTranslate &&
           std::fabs(scale - 1.0f) <= gScaleEpsilon;
}
