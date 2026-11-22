// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and the community declarations only
// 0x1565300 ImageSpaceEffect::~ImageSpaceEffect
// Adapted bodies: none
// ImageSpaceEffect::~ImageSpaceEffect: GUESS(low); the this-adjusting deleting-destructor thunk
// Prefix90, ThunkHost: GUESS(low); stand-ins that place the secondary base at the thunk's offset
// Source exposure: community-headers (CommonLibSSE-NG declarations).
#include "ImageSpaceEffect.h"

class Prefix90
{
public:
    virtual ~Prefix90() {}
    std::uint8_t pad[0x88];
};
static_assert(sizeof(Prefix90) == 0x90, "layout");

// The secondary base sits at 0x90; its vftable carries the compared adjustor thunk.
class ThunkHost : public Prefix90, public ImageSpaceEffect
{
public:
    ThunkHost();
    ~ThunkHost() override;
};

ThunkHost::ThunkHost()
{
}

ThunkHost::~ThunkHost()
{
}

bool ImageSpaceEffect::IsActive()
{
    return active;
}
