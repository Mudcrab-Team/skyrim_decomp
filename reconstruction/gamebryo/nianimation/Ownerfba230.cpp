// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf687b0 (gamebryo/nianimation/NiBlendFloatInterpolator_f687b0): source copied, names replaced by placeholders.
// 0xfba230 Ownerfba230::Functionfba230
#include "Ownerfba230.h"

// An out-of-line constructor emits the compiler-generated deleting destructor.
Ownerfba230::Ownerfba230() = default;

// guess: same compiled code as matched 0xf687b0 apart from relocated fields; its role here is not established.
void Ownerfba230::Functionfba230(Ownerfba230* dest, NiCloningProcess& cloning)
{
    NiBlendInterpolator::CopyMembers(dest, cloning);
    dest->value = value;
}
