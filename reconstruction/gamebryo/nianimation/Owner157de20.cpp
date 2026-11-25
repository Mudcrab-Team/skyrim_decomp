// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf7ab50 (gamebryo/nianimation/NiBSplinePoint3Interpolator_f7ab50): source copied, names replaced by placeholders.
// 0x157de20 Owner157de20::Function157de20
#include "Owner157de20.h"

// guess: same compiled code as matched 0xf7ab50 apart from relocated fields; its role here is not established.
void Owner157de20::Function157de20(Owner157de20* dest, NiCloningProcess& cloning)
{
    NiBSplineInterpolator::CopyMembers(dest, cloning);
    dest->value.x = value.x;
    dest->value.y = value.y;
    dest->value.z = value.z;
    dest->channelHandle = channelHandle;
}

Owner157de20::Owner157de20(NiBSplineData* data, std::uint32_t handle, NiBSplineBasisData* basis) :
    NiBSplineInterpolator(data, basis), value{}

, channelHandle(handle)
{
}

Owner157de20::Owner157de20(const NiPoint3& value) :
    NiBSplineInterpolator(nullptr, nullptr), value{value.x, value.y, value.z}

, channelHandle(0xFFFFu)
{
}
