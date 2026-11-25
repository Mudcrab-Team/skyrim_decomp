// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image. Stamped as a twin of matched 0xf2dae0 (gamebryo/nimain/NiBoxBV_f2dae0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x55e6b0 Owner55e6b0::Function55e6b0
#include "Owner55e6b0.h"

// guess: same compiled code as matched 0xf2dae0 apart from relocated fields; its role here is not established.
void Owner55e6b0::Function55e6b0(NiStream& stream)
{
    NiBoundingVolume::LoadBinary(stream);
    return box.LoadBinary(stream);
}
