// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses.
// NiBSplinePoint3Interpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, GetChannelPosed, GetChannelHandle, SetChannelHandle, value, channelHandle: GUESS(low)
#pragma once

#include "NiBSplineInterpolator.h"

// NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class NiBSplinePoint3Interpolator : public NiBSplineInterpolator
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    void CopyMembers(NiBSplinePoint3Interpolator* dest, NiCloningProcess& cloning);
    NiBSplinePoint3Interpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplinePoint3Interpolator(const NiPoint3& value);
    bool GetChannelPosed(std::uint16_t channel) const;
    std::uint32_t GetChannelHandle(std::uint16_t channel) const;
    void SetChannelHandle(std::uint32_t handle, std::uint16_t channel);
    ~NiBSplinePoint3Interpolator() override = default;

private:
    NiPoint3 value;
    std::uint32_t channelHandle;
};
static_assert(sizeof(NiBSplinePoint3Interpolator) == 0x40, "interpolator size");
