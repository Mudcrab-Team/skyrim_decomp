// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented6398b0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/forms/BGSSaveFormBufferLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/B/BGSSaveFormBuffer.h; MIT.
// BGSSaveFormBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// F004Represented6398b0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../support/BGSSaveGameBufferLayout.h"

namespace ResearchLayouts {
class TESForm;
class F004Represented6398b0 : public BGSSaveGameBufferLayout {
public:
    virtual ~F004Represented6398b0();
    std::uint64_t unk18;
    std::uint64_t unk20;
    TESForm* form;
};
static_assert(sizeof(F004Represented6398b0) == 48, "community represented size");
static_assert(offsetof(F004Represented6398b0, unk18) == 24, "unk18 offset");
static_assert(offsetof(F004Represented6398b0, unk20) == 32, "unk20 offset");
static_assert(offsetof(F004Represented6398b0, form) == 40, "form offset");
}
