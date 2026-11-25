// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the blend value and associated flag follow the pinned accesses. Stamped as a twin of matched 0xf687b0 (gamebryo/nianimation/NiBlendFloatInterpolator_f687b0): source copied, names replaced by placeholders.
// Functionfba230, Ownerfba230: GUESS(low) STANDIN
// LoadBinary, SaveBinary, IsEqual, SupportsBlendValue, value: GUESS(low) STANDIN
#pragma once
#include "NiBlendFloatInterpolator_f687b0.h"

class Ownerfba230 : public NiBlendInterpolator
{
public:
    Ownerfba230();
    void Functionfba230(Ownerfba230* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    bool SupportsBlendValue(const BlendValueSupport* input) const;
    ~Ownerfba230() override = default;

private:
    float value;
};
static_assert(sizeof(Ownerfba230) == 0x50, "blend interpolator size");
