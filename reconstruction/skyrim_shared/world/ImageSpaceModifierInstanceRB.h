// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: names from meh321/AddressLibraryDatabase (permission); the layout stand-in is written from the listed class size
// Adapted bodies: none
// ImageSpaceModifierInstanceRB, ImageSpaceModifierInstanceRB::~ImageSpaceModifierInstanceRB: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ImageSpaceModifierInstanceRB
{
public:
    ImageSpaceModifierInstanceRB();           // defined so the vftable and its deleting destructor are emitted
    virtual ~ImageSpaceModifierInstanceRB();  // compared: 0x2a5670; declared but left undefined

    std::uint64_t unknown08[14];  // 08 .. 77
};
static_assert(sizeof(ImageSpaceModifierInstanceRB) == 0x78, "size observed from the sized delete argument");
