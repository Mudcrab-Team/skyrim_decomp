// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: Written for this reconstruction from the listing; names from the community-derived header.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1573b0 ExtraDataList::Function1573b0
// 0x1573e0 ExtraDataList::Function1573e0
// Adapted bodies: none
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "ExtraDataList.h"

namespace ResearchLayouts {
// BSExtraData, PresenceBitfield: GUESS(low); minimal stand-in layouts
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
struct PresenceBitfield { std::uint8_t bits[0x17]; };

unsigned int ExtraDataList::Function1573b0() const
{
    unsigned int count = 0;
    for (BSExtraData* cur = list.data; cur; cur = cur->next) {
        ++count;
    }
    return count;
}

bool ExtraDataList::Function1573e0(unsigned int type) const
{
    PresenceBitfield* presence = list.presence;
    if (!presence) {
        return false;
    }
    unsigned int index = type >> 3;
    if (index >= 0x17) {
        return false;
    }
    return (presence->bits[index] & (1u << (type & 7))) != 0;
}

}
