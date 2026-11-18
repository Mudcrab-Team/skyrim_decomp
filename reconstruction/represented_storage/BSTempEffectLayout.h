// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BSTempEffect.h; MIT.
// BSTempEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTempEffectLayout: GUESS(medium) STANDIN
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include "NiObjectLayout.h"

namespace ResearchLayouts {
class TESObjectCELL;
class BSTempEffectLayout : public NiObjectLayout {
public:
    virtual ~BSTempEffectLayout();
    float lifetime;
    TESObjectCELL* cell;
    float age;
    bool initialized;
    std::uint32_t effectID;
};
static_assert(sizeof(BSTempEffectLayout) == 48, "community represented size");
static_assert(offsetof(BSTempEffectLayout, lifetime) == 16, "lifetime offset");
static_assert(offsetof(BSTempEffectLayout, cell) == 24, "cell offset");
static_assert(offsetof(BSTempEffectLayout, age) == 32, "age offset");
static_assert(offsetof(BSTempEffectLayout, initialized) == 36, "initialized offset");
static_assert(offsetof(BSTempEffectLayout, effectID) == 40, "effectID offset");
}
