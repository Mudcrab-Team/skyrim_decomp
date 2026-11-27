// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by deepseek-v4.1-flash; class, member and base names come from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied.
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// 0xff6bb0 BSSubIndexTriShape::AsSubIndexTriShape
// 0x51a6c0 BSSubIndexTriShape::GetNumSegments
// Adapted bodies: none
#include "BSSubIndexTriShape.h"

BSSubIndexTriShape* BSSubIndexTriShape::AsSubIndexTriShape()
{
    return this;
}

// A non-segmented shape is treated as one segment.
std::uint32_t BSSubIndexTriShape::GetNumSegments()
{
    if (nonSegmented) {
        return 1;
    }
    return numSegments;
}
