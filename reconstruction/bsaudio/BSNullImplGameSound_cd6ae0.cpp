// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0xcd6ae0 BSNullImplGameSound::Functioncd6ae0
// 0xcd6b10 BSNullImplGameSound::Functioncd6b10
// 0xcd6b40 BSNullImplGameSound::Functioncd6b40
// 0xcd6b70 BSNullImplGameSound::Functioncd6b70
// 0xcd6be0 BSNullImplGameSound::Functioncd6be0
#include "BSNullImplGameSound_cd6ae0.h"


bool BSNullImplGameSound::Functioncd6ae0()
{
    Functioncd5af0();
    if ((soundFlags & 0x3800u) == 0) {
        stateFlags &= ~0x20u;
    }
    return true;
}

void BSNullImplGameSound::Functioncd6b10(const NiPoint3& value)
{
    position.x = value.x;
    position.y = value.y;
    position.z = value.z;
}

void BSNullImplGameSound::Functioncd6b40(NiPoint3& value) const
{
    value.x = position.x;
    value.y = position.y;
    value.z = position.z;
}

void BSNullImplGameSound::Functioncd6b70(float first, float second)
{
    value78 = first;
    value74 = second;
}

void BSNullImplGameSound::Functioncd6be0()
{
    stateFlags &= ~0x20u;
    stateFlags |= 0x40u;
}
