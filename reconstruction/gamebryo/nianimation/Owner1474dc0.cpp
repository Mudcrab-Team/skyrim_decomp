// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf81060 (gamebryo/nianimation/NiLookAtInterpolator_f80030): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1474dc0 Owner1474dc0::Function1474dc0
#include "Owner1474dc0.h"

void AssignFixedString_1474dc0(BSFixedString& dest, const BSFixedString& source);

// guess: same compiled code as matched 0xf81060 apart from relocated fields; its role here is not established.
void Owner1474dc0::Function1474dc0(const BSFixedString& name)
{
    return AssignFixedString_1474dc0(targetName, name);
}
