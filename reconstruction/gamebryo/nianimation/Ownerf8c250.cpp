// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf74630 (gamebryo/nianimation/NiBlendQuaternionInterpolator_f74630): source copied, names replaced by placeholders.
// 0xf8c250 Ownerf8c250::Functionf8c250
#include "Ownerf8c250.h"

// An out-of-line constructor emits the compiler-generated deleting destructor.
Ownerf8c250::Ownerf8c250() = default;

// guess: same compiled code as matched 0xf74630 apart from relocated fields; its role here is not established.
void Ownerf8c250::Functionf8c250(Ownerf8c250* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
}
