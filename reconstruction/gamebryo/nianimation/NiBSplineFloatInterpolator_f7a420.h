// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline prefixes and handle fields follow pinned accesses and the cited base declarations.
// NiBSplineFloatInterpolator, NiBSplineInterpolator: EXE_RTTI
// NiInterpolator, NiCloningProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiBSplineData, NiBSplineBasisData, CopyMembers, GetControlPointCount, channelHandle, value, padding: STANDIN GUESS(low)
// GetChannelPosed, SetChannelHandle: GUESS(low); the float channel reads whether it has control points and stores a handle.
#pragma once

#include <cstdint>
#include "NiInterpolator.h"

class NiBSplineData;
class NiBSplineBasisData;

class NiBSplineInterpolator : public NiInterpolator
{
public:
    NiBSplineInterpolator(NiBSplineData* data, NiBSplineBasisData* basis);
    bool IsEqual(NiObject* other) override;
    void CopyMembers(NiBSplineInterpolator* dest, NiCloningProcess& cloning);
    virtual void FunctionSlot39();
    virtual std::uint32_t GetControlPointCount(std::uint16_t channel) const;

private:
    std::uint8_t padding18[0x18];
};
static_assert(sizeof(NiBSplineInterpolator) == 0x30, "spline base size");

class NiBSplineFloatInterpolator : public NiBSplineInterpolator
{
public:
    void CopyMembers(NiBSplineFloatInterpolator* dest, NiCloningProcess& cloning);
    NiBSplineFloatInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplineFloatInterpolator(float value);
    bool GetChannelPosed(std::uint16_t channel) const;
    void SetChannelHandle(std::uint32_t handle, std::uint16_t channel);

private:
    float value;
    std::uint32_t channelHandle;
};
static_assert(sizeof(NiBSplineFloatInterpolator) == 0x38, "float spline size");
