// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by deepseek-v4.1-flash; class, member and base names come from CommonLibSSE-NG (MIT) and powerof3/CommonLibSSE (GPL-3.0); no external implementation body is copied.
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// BSSubIndexTriShape, BSTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::AsSubIndexTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the base virtual this unit overrides, declared by NG in NiObject.h; no checkout declares the BSSubIndexTriShape override itself
// SegmentData, segmentData, numSegments, unkSegCount, unk170, nonSegmented: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// GetNumSegments: GUESS(low); the name is inferred from the body, which answers one for a non-segmented shape and the stored count otherwise
#pragma once

#include <cstdint>
#include "BSInstanceTriShape.h"

struct SegmentData;

class BSSubIndexTriShape : public BSTriShape
{
public:
    virtual ~BSSubIndexTriShape();

    // The virtual slot order is not compared here; only the body below is.
    virtual BSSubIndexTriShape* AsSubIndexTriShape();  // compared: 0xff6bb0

    std::uint32_t GetNumSegments();

    SegmentData* segmentData;   // 160
    std::uint32_t numSegments;  // 168
    std::uint32_t unkSegCount;  // 16C
    bool unk170;                // 170
    bool nonSegmented;          // 171
};
static_assert(sizeof(BSSubIndexTriShape) == 0x178, "BSSubIndexTriShape size");
