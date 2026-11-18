// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/M/ModManagerData.h; GPL-3.0.
// ModManagerData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ModManagerDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ModManagerDataLayout.h.
// ModManagerDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "IUIMessageDataStorageLayout.h"

namespace ResearchLayouts {
class ModManagerDataStorageLayout : public IUIMessageDataStorageLayout {
public:
    virtual ~ModManagerDataStorageLayout();
    bool useTransparentBackground;
};
static_assert(sizeof(ModManagerDataStorageLayout) == 24, "community represented size");
static_assert(offsetof(ModManagerDataStorageLayout, useTransparentBackground) == 16, "useTransparentBackground offset");
}
