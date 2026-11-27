// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf81060 (gamebryo/nianimation/NiLookAtInterpolator_f80030): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x12cc260 Owner12cc260::Function12cc260
#include "Owner12cc260.h"

void AssignFixedString_12cc260(BSFixedString& dest, const BSFixedString& source);

// guess: same compiled code as matched 0xf81060 apart from relocated fields; its role here is not established.
void Owner12cc260::Function12cc260(const BSFixedString& name)
{
    return AssignFixedString_12cc260(targetName, name);
}
