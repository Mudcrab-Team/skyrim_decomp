// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/M/ModManagerData.h; GPL-3.0.
// ModManagerData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ModManagerDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/IUIMessageDataLayout.h"

namespace ResearchLayouts {
class ModManagerDataLayout : public IUIMessageDataLayout {
public:
    virtual ~ModManagerDataLayout();
    bool useTransparentBackground;
};
static_assert(sizeof(ModManagerDataLayout) == 24, "community represented size");
static_assert(offsetof(ModManagerDataLayout, useTransparentBackground) == 16, "useTransparentBackground offset");
}
