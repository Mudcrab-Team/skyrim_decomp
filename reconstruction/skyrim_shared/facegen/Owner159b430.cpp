// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of keyframe accessors. Stamped as a twin of matched 0x4324d0 (skyrim_shared/facegen/BSFaceGenKeyframeExclusive): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/o2-fpfast.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x159b430 Owner159b430::Function159b430
#include "Owner159b430.h"

// guess: same compiled code as matched 0x4324d0 apart from relocated fields; its role here is not established.
std::uint8_t Owner159b430::Function159b430() const
{
    return field10;
}
