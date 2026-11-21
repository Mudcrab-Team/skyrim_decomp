// Source exposure: mixed (pinned image listing and cited public declarations).
// Code origin: original reconstruction from the pinned instruction listing; no body adapted.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPoint3Interpolator: EXE_RTTI
// IsPoint3ValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiKeyBasedInterpolator, NiObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); the database name list carries NiPoint3Interpolator::IsEqual_*, and the body calls NiObject::IsEqual on the key data
// pose, data, cachedKeyIndex: GUESS(low); members named for the measured accesses: point at 0x18, key data at 0x28, cached index at 0x30
#pragma once
#include <cstdint>
#include "NiKeyBasedInterpolator.h"

struct NiPoint3
{
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 0xC, "point size");

// IsEqualInterpolatorBase: GUESS(low); the base IsEqual body the interpolator calls with itself and the compared object; declared here because the base header is outside this unit's edit scope
bool IsEqualInterpolatorBase(NiKeyBasedInterpolator& a_self, NiObject* a_object);

class NiPoint3Interpolator : public NiKeyBasedInterpolator
{
public:
    virtual std::uint8_t IsPoint3ValueSupported() const;
    bool IsEqual(NiObject* a_object);

private:
    NiPoint3 pose;                 // 18
    NiObject* data;                // 28
    std::uint32_t cachedKeyIndex;  // 30
};
static_assert(sizeof(NiPoint3Interpolator) == 0x38, "interpolator size");
