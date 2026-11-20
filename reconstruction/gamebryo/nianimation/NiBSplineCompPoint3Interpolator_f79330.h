// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses.
// NiBSplineCompPoint3Interpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, compressionParameters, value, channelHandle, padding: GUESS(low)
#pragma once

#include "NiBSplinePoint3Interpolator_f7ab50.h"

class NiBSplineCompPoint3Interpolator : public NiBSplinePoint3Interpolator
{
public:
    void CopyMembers(NiBSplineCompPoint3Interpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    NiBSplineCompPoint3Interpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplineCompPoint3Interpolator(const NiPoint3& value);
    ~NiBSplineCompPoint3Interpolator() override = default;

private:
    float compressionParameters[2];
};
static_assert(sizeof(NiBSplineCompPoint3Interpolator) == 0x48, "interpolator size");
