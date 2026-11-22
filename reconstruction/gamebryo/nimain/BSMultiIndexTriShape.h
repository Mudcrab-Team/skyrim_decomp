// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT), and no external implementation body or layout is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// 0x15754b0 compared function
// BSMultiIndexTriShape, BSMultiIndexTriShape::AsMultiIndexTriShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

// Function15754b0, target, TargetView: GUESS(low); names invented, offsets read from the listing.
struct TargetView
{
    std::uint8_t unknown00[0x60];  // 00
    void* value;                   // 60
};

class BSMultiIndexTriShape {
public:
    virtual ~BSMultiIndexTriShape();

    // The virtual slot order is not compared here; only the body below is.
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();  // compared: 0x1575450
    void Function15754b0(void* a_value);  // compared: 0x15754b0

    std::uint8_t unknown08[0x1a8];  // 08
    TargetView* target;             // 1B0
};
