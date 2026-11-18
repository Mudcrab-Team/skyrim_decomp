// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/ImageSpaceModifierInstance.h; MIT.
// ImageSpaceModifierInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstanceLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSFixedStringLayout.h"
#include "gamebryo/nimain/NiObjectLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class ImageSpaceModifierInstanceLayout : public NiObjectLayout {
public:
    virtual ~ImageSpaceModifierInstanceLayout();
    std::uint32_t unk10;
    float strength;
    NiPointerLayout<NiAVObject> target;
    float age;
    std::uint32_t flags;
};
static_assert(sizeof(ImageSpaceModifierInstanceLayout) == 40, "community represented size");
static_assert(offsetof(ImageSpaceModifierInstanceLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(ImageSpaceModifierInstanceLayout, strength) == 20, "strength offset");
static_assert(offsetof(ImageSpaceModifierInstanceLayout, target) == 24, "target offset");
static_assert(offsetof(ImageSpaceModifierInstanceLayout, age) == 32, "age offset");
static_assert(offsetof(ImageSpaceModifierInstanceLayout, flags) == 36, "flags offset");
}
