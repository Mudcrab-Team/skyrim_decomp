// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf81060 (gamebryo/nianimation/NiLookAtInterpolator_f80030): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3eccf0 Owner3eccf0::Function3eccf0
#include "Owner3eccf0.h"

void AssignFixedString_3eccf0(BSFixedString& dest, const BSFixedString& source);

// guess: same compiled code as matched 0xf81060 apart from relocated fields; its role here is not established.
void Owner3eccf0::Function3eccf0(const BSFixedString& name)
{
    return AssignFixedString_3eccf0(targetName, name);
}
