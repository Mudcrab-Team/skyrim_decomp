// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineColorInterpolator: EXE_RTTI
// value, channelHandle: GUESS(low)
// NiColorA, red, green, blue, alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiColorA::LoadBinary, NiColorA::SaveBinary: GUESS(low)
#pragma once

#include "NiBSplineInterpolator_f77f50.h"

struct NiColorA
{
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream) const;

    float red;
    float green;
    float blue;
    float alpha;
};

class NiBSplineColorInterpolator : public NiBSplineInterpolator
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;

private:
    NiColorA value;
    std::uint32_t channelHandle;
};
