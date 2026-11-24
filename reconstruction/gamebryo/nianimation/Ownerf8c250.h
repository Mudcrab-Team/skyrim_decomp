// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses. Stamped as a twin of matched 0xf74630 (gamebryo/nianimation/NiBlendQuaternionInterpolator_f74630): source copied, names replaced by placeholders.
// Functionf8c250, Ownerf8c250: GUESS(low) STANDIN
// LoadBinary, SaveBinary, SupportsBlendValue, value: GUESS(low) STANDIN
#pragma once
#include "NiBlendQuaternionInterpolator_f74630.h"

class Ownerf8c250 : public NiBlendInterpolator
{
public:
    Ownerf8c250();
    void Functionf8c250(Ownerf8c250* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~Ownerf8c250() override = default;

private:
    NiQuaternion value;
};
static_assert(sizeof(Ownerf8c250) == 0x58, "blend interpolator size");
