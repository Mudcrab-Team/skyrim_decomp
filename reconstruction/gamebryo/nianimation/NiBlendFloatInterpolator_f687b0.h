// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses.
// NiBlendFloatInterpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, SupportsBlendValue, value, valid: GUESS(low)
#pragma once

#include "NiBlendInterpolator.h"

class NiBlendFloatInterpolator : public NiBlendInterpolator
{
public:
    NiBlendFloatInterpolator();
    void CopyMembers(NiBlendFloatInterpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~NiBlendFloatInterpolator() override = default;

private:
    float value;
};
static_assert(sizeof(NiBlendFloatInterpolator) == 0x50, "blend interpolator size");
