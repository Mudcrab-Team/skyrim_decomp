// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses.
// NiBSplineCompColorInterpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, compressionParameters, value, channelHandle, padding: GUESS(low)
#pragma once

#include "NiBSplineColorInterpolator_f77f10.h"

class NiBSplineCompColorInterpolator : public NiBSplineColorInterpolator
{
public:
    void CopyMembers(NiBSplineCompColorInterpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    NiBSplineCompColorInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplineCompColorInterpolator(const NiColorA& value);
    ~NiBSplineCompColorInterpolator() override = default;

private:
    float compressionParameters[2];
};
static_assert(sizeof(NiBSplineCompColorInterpolator) == 0x50, "interpolator size");
