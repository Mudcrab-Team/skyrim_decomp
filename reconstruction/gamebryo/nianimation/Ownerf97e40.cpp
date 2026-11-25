// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf740f0 (gamebryo/nianimation/NiBlendPoint3Interpolator_f73b10): source copied, names replaced by placeholders.
// 0xf97e40 Ownerf97e40::Functionf97e40
#include "Ownerf97e40.h"

// An out-of-line constructor emits the compiler-generated deleting destructor.
Ownerf97e40::Ownerf97e40() = default;

// guess: same compiled code as matched 0xf740f0 apart from relocated fields; its role here is not established.
bool Ownerf97e40::Functionf97e40(const BlendValueSupport* input) const
{
    return input->IsPoint3ValueSupported();
}
