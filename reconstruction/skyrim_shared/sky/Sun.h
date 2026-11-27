// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: written from the pinned listing for 0x41cbb0; the other Sun functions are not in this unit.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Base form: shared header generated/crashlogger_pdb/types/SkyObject.h for SkyObject.
// Sun: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sun::GetSunPositionData: GUESS(low); the name comes from the inventory.
// Sky: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode, NiPoint3: STANDIN GUESS(low); the translation offset 6C is read from the listing.
// unknown10: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include "generated/crashlogger_pdb/types/SkyObject.h"

class Sky;

struct NiPoint3 {
    float x;
    float y;
    float z;
};

// NiNode: STANDIN GUESS(low); only the translation at 6C is declared.
struct NiNode {
    std::uint8_t unk00[0x6C];
    // NiNode::translate: GUESS(low); offset 6C from the listing
    NiPoint3 translate;
};

// Virtual slots (00 dtor, 02 Init, 03 Update) are omitted: SkyObject carries the vtable pointer as a
// plain member, so a virtual here would add a second one and change the size.
class Sun : public SkyObject
{
public:
    void GetSunPositionData(NiPoint3* a_out);  // compared: 0x41cbb0

    std::uint8_t unknown10[0x48];  // 10
};
static_assert(sizeof(Sun) == 0x58, "Sun size");
