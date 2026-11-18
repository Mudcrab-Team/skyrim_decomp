// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CharEvent.h; MIT.
// CharEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CharEventLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsinput/InputEventLayout.h"

namespace ResearchLayouts {
class CharEventLayout : public InputEventLayout {
public:
    virtual ~CharEventLayout();
    std::uint32_t keycode;
};
static_assert(sizeof(CharEventLayout) == 32, "community represented size");
static_assert(offsetof(CharEventLayout, keycode) == 24, "keycode offset");
}
