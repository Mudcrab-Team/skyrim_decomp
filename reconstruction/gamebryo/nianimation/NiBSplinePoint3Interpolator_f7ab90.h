// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplinePoint3Interpolator: EXE_RTTI
// value, channelHandle: GUESS(low)
// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3::LoadBinary, NiPoint3::SaveBinary: GUESS(low)
#pragma once

#include "NiBSplineInterpolator_f77f50.h"

struct NiPoint3
{
    void LoadBinary(NiStream& stream);
    void SaveBinary(NiStream& stream) const;

    float x;
    float y;
    float z;
};

class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;

private:
    NiPoint3 value;
    std::uint32_t channelHandle;
};
