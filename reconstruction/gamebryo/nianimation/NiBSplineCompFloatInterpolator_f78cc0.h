// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses.
// NiBSplineCompFloatInterpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, compressionParameters, value, channelHandle, padding: GUESS(low)
#pragma once

#include "NiBSplineInterpolator.h"

// NiBSplineFloatInterpolator: STANDIN EXE_RTTI
class NiBSplineFloatInterpolator : public NiBSplineInterpolator
{
public:
    NiBSplineFloatInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplineFloatInterpolator(float value);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    void CopyMembers(NiBSplineFloatInterpolator* dest, NiCloningProcess& cloning);

private:
    float value;
    std::uint32_t channelHandle;
};
static_assert(sizeof(NiBSplineFloatInterpolator) == 0x38, "uncompressed parent size");

class NiBSplineCompFloatInterpolator : public NiBSplineFloatInterpolator
{
public:
    void CopyMembers(NiBSplineCompFloatInterpolator* dest, NiCloningProcess& cloning);
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    NiBSplineCompFloatInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplineCompFloatInterpolator(float value);
    ~NiBSplineCompFloatInterpolator() override = default;

private:
    float compressionParameters[2];
};
static_assert(sizeof(NiBSplineCompFloatInterpolator) == 0x40, "interpolator size");
