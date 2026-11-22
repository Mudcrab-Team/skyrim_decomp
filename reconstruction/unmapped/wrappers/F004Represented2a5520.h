// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented2a5520, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/ImageSpaceModifierInstanceLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/ImageSpaceModifierInstance.h; MIT.
// ImageSpaceModifierInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented2a5520: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "unmapped/support/BSFixedStringLayout.h"
#include "unmapped/support/NiObjectLayout.h"

namespace ResearchLayouts {
class NiAVObject;
class F004Represented2a5520 : public NiObjectLayout {
public:
    virtual ~F004Represented2a5520();
    std::uint32_t unk10;
    float strength;
    NiPointerLayout<NiAVObject> target;
    float age;
    std::uint32_t flags;
};
static_assert(sizeof(F004Represented2a5520) == 40, "community represented size");
static_assert(offsetof(F004Represented2a5520, unk10) == 16, "unk10 offset");
static_assert(offsetof(F004Represented2a5520, strength) == 20, "strength offset");
static_assert(offsetof(F004Represented2a5520, target) == 24, "target offset");
static_assert(offsetof(F004Represented2a5520, age) == 32, "age offset");
static_assert(offsetof(F004Represented2a5520, flags) == 36, "flags offset");
}
