// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/ImageSpaceModifierInstance.h; MIT.
// ImageSpaceModifierInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstanceLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ImageSpaceModifierInstanceLayout.h.
// ImageSpaceModifierInstanceStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../../bscore/BSFixedStringStorageLayout.h"
#include "gamebryo/nimain/NiObjectStorageLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class ImageSpaceModifierInstanceStorageLayout : public NiObjectStorageLayout {
public:
    virtual ~ImageSpaceModifierInstanceStorageLayout();
    std::uint32_t unk10;
    float strength;
    NiPointerStorageLayout<NiAVObject> target;
    float age;
    std::uint32_t flags;
};
static_assert(sizeof(ImageSpaceModifierInstanceStorageLayout) == 40, "community represented size");
static_assert(offsetof(ImageSpaceModifierInstanceStorageLayout, unk10) == 16, "unk10 offset");
static_assert(offsetof(ImageSpaceModifierInstanceStorageLayout, strength) == 20, "strength offset");
static_assert(offsetof(ImageSpaceModifierInstanceStorageLayout, target) == 24, "target offset");
static_assert(offsetof(ImageSpaceModifierInstanceStorageLayout, age) == 32, "age offset");
static_assert(offsetof(ImageSpaceModifierInstanceStorageLayout, flags) == 36, "flags offset");
}
