// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/InputEvent.h; MIT.
// InputEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// InputEventLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class InputEventLayout {
public:
    virtual ~InputEventLayout();
    std::uint32_t device;
    std::uint32_t eventType;
    InputEventLayout* next;
};
static_assert(sizeof(InputEventLayout) == 24, "community represented size");
static_assert(offsetof(InputEventLayout, device) == 8, "device offset");
static_assert(offsetof(InputEventLayout, eventType) == 12, "eventType offset");
static_assert(offsetof(InputEventLayout, next) == 16, "next offset");
}
