// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x2a8ab0 NiFloatData::ctor
#include "NiFloatData_2a8ab0.h"

// Construct an empty NiFloatData keyframe container.
NiFloatData::NiFloatData() :
    NiObject(),
    numKeys(0),
    keys(nullptr),
    keyType(0),
    keySize(0)
{
}
