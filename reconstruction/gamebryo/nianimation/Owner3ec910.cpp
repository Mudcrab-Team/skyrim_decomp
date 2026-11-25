// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf81060 (gamebryo/nianimation/NiLookAtInterpolator_f80030): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x3ec910 Owner3ec910::Function3ec910
#include "Owner3ec910.h"

void AssignFixedString_3ec910(BSFixedString& dest, const BSFixedString& source);

// guess: same compiled code as matched 0xf81060 apart from relocated fields; its role here is not established.
void Owner3ec910::Function3ec910(const BSFixedString& name)
{
    return AssignFixedString_3ec910(targetName, name);
}
