// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x2a8a80 NiColorData::ctor
#include "NiColorData_2a8a80.h"

// Construct an empty NiColorData keyframe container.
NiColorData::NiColorData() :
    NiObject(),
    numKeys(0),
    keys(nullptr),
    keyType(0),
    keySize(0)
{
}
