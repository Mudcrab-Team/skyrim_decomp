// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBSplineInterpolator, NiBSplineData, NiBSplineBasisData: STANDIN EXE_RTTI
// NiObject::LoadBinary, NiObject::SaveBinary, NiObject::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown18: GUESS(low)
#pragma once

#include "bssystem/NiStream_19e930.h"

class NiBSplineData;
class NiBSplineBasisData;

class NiBSplineInterpolator : public NiInterpolator
{
public:
    NiBSplineInterpolator(NiBSplineData* data, NiBSplineBasisData* basis);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* object) override;

private:
    std::uint8_t unknown18[0x18];
};
static_assert(sizeof(NiBSplineInterpolator) == 0x30, "spline base size");
