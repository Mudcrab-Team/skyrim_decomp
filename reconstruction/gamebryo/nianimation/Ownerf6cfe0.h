// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses. Stamped as a twin of matched 0xf687b0 (gamebryo/nianimation/NiBlendFloatInterpolator_f687b0): source copied, names replaced by placeholders.
// Functionf6cfe0, Ownerf6cfe0: GUESS(low) STANDIN
// LoadBinary, SaveBinary, IsEqual, SupportsBlendValue, value: GUESS(low) STANDIN
#pragma once
#include "NiBlendFloatInterpolator_f687b0.h"

class Ownerf6cfe0 : public NiBlendInterpolator
{
public:
    Ownerf6cfe0();
    void Functionf6cfe0(Ownerf6cfe0* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~Ownerf6cfe0() override = default;

private:
    float value;
};
static_assert(sizeof(Ownerf6cfe0) == 0x50, "blend interpolator size");
