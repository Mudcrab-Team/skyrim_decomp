// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses.
// NiBlendQuaternionInterpolator: EXE_RTTI
// LoadBinary, SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, SupportsBlendValue, value, valid: GUESS(low)
#pragma once

#include "NiBlendInterpolator.h"

// NiQuaternion, w, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiQuaternion
{
public:
    float w;
    float x;
    float y;
    float z;
};

class NiBlendQuaternionInterpolator : public NiBlendInterpolator
{
public:
    NiBlendQuaternionInterpolator();
    void CopyMembers(NiBlendQuaternionInterpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~NiBlendQuaternionInterpolator() override = default;

private:
    NiQuaternion value;
};
static_assert(sizeof(NiBlendQuaternionInterpolator) == 0x58, "blend interpolator size");
