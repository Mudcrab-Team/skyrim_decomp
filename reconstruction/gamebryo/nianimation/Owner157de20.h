// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial spline value and parameter layout follows the pinned accesses. Stamped as a twin of matched 0xf7ab50 (gamebryo/nianimation/NiBSplinePoint3Interpolator_f7ab50): source copied, names replaced by placeholders.
// Function157de20, Owner157de20: GUESS(low) STANDIN
// LoadBinary, SaveBinary, IsEqual, GetChannelPosed, GetChannelHandle, SetChannelHandle, value, channelHandle: GUESS(low) STANDIN
#pragma once
#include "NiBSplinePoint3Interpolator_f7ab50.h"

class Owner157de20 : public NiBSplineInterpolator
{
public:
    void LoadBinary(NiStream& stream) override;
    void SaveBinary(NiStream& stream) override;
    bool IsEqual(NiObject* other) override;
    void Function157de20(Owner157de20* dest, NiCloningProcess& cloning);
    Owner157de20(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis);
    Owner157de20(const NiPoint3& value);
    bool GetChannelPosed(std::uint16_t channel) const;
    std::uint32_t GetChannelHandle(std::uint16_t channel) const;
    void SetChannelHandle(std::uint32_t handle, std::uint16_t channel);
    ~Owner157de20() override = default;

private:
    NiPoint3 value;
    std::uint32_t channelHandle;
};
static_assert(sizeof(Owner157de20) == 0x40, "interpolator size");
