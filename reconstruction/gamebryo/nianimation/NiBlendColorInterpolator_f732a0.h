// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses.
// NiBlendColorInterpolator: EXE_RTTI
// SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, SupportsBlendValue, value, valid: GUESS(low)
#pragma once

#include "NiBlendInterpolator.h"

// NiColorA, red, green, blue, alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiColorA
{
public:
    float red;
    float green;
    float blue;
    float alpha;
};

class NiBlendColorInterpolator : public NiBlendInterpolator
{
public:
    NiBlendColorInterpolator();
    void CopyMembers(NiBlendColorInterpolator* dest, NiCloningProcess& cloning);
    void SaveBinary(NiStream& stream) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~NiBlendColorInterpolator() override = default;

private:
    NiColorA value;
    bool valid;
};
static_assert(sizeof(NiBlendColorInterpolator) == 0x60, "blend interpolator size");
