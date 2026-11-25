// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses. Stamped as a twin of matched 0xf740f0 (gamebryo/nianimation/NiBlendPoint3Interpolator_f73b10): source copied, names replaced by placeholders.
// Functionf97e40, Ownerf97e40: GUESS(low) STANDIN
// SaveBinary, IsEqual, CopyMembers, value, valid: GUESS(low) STANDIN
#pragma once
#include "NiBlendPoint3Interpolator_f73b10.h"

class Ownerf97e40 : public NiBlendInterpolator
{
public:
    Ownerf97e40();
    void CopyMembers(Ownerf97e40* dest, NiCloningProcess& cloning);
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    bool Functionf97e40(const BlendValueSupport* input) const;
    ~Ownerf97e40() override = default;

private:
    NiPoint3 value;
    bool valid;
};
static_assert(sizeof(Ownerf97e40) == 0x58, "blend interpolator size");
