// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses.
// NiBSplineColorInterpolator: EXE_RTTI
// LoadBinary, SaveBinary, IsEqual: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CopyMembers, GetChannelPosed, GetChannelHandle, SetChannelHandle, value, channelHandle: GUESS(low)
#pragma once

#include "NiBSplineInterpolator.h"

// NiColorA, red, green, blue, alpha: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiColorA
{
public:
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
    bool IsEqual(NiObject* other) override;
    void CopyMembers(NiBSplineColorInterpolator* dest, NiCloningProcess& cloning);
    NiBSplineColorInterpolator(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    NiBSplineColorInterpolator(const NiColorA& value);
    bool GetChannelPosed(std::uint16_t channel) const;
    std::uint32_t GetChannelHandle(std::uint16_t channel) const;
    void SetChannelHandle(std::uint32_t handle, std::uint16_t channel);
    ~NiBSplineColorInterpolator() override = default;

private:
    NiColorA value;
    std::uint32_t channelHandle;
};
static_assert(sizeof(NiBSplineColorInterpolator) == 0x48, "interpolator size");
