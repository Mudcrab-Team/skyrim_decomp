// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses.
// NiBlendPoint3Interpolator: EXE_RTTI
// SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, SupportsBlendValue, value, valid: GUESS(low)
#pragma once

#include "NiBlendInterpolator.h"

// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class NiBlendPoint3Interpolator : public NiBlendInterpolator
{
public:
    NiBlendPoint3Interpolator();
    void CopyMembers(NiBlendPoint3Interpolator* dest, NiCloningProcess& cloning);
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~NiBlendPoint3Interpolator() override = default;

private:
    NiPoint3 value;
    bool valid;
};
static_assert(sizeof(NiBlendPoint3Interpolator) == 0x58, "blend interpolator size");
