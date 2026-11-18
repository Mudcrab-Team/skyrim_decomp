// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IUIMessageData.h; MIT.
// IUIMessageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// IUIMessageDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
class IUIMessageDataLayout {
public:
    virtual ~IUIMessageDataLayout();
    std::uint16_t unk08;
};
static_assert(sizeof(IUIMessageDataLayout) == 16, "community represented size");
static_assert(offsetof(IUIMessageDataLayout, unk08) == 8, "unk08 offset");
}
