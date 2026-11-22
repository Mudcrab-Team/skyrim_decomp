// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/L/LoadingMenuData.h; GPL-3.0.
// LoadingMenuData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// LoadingMenuDataLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/LoadingMenuDataLayout.h.
// LoadingMenuDataStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsscaleform/IUIMessageDataStorageLayout.h"

namespace ResearchLayouts {
class BGSLocation;
class LoadingMenuDataStorageLayout : public IUIMessageDataStorageLayout {
public:
    virtual ~LoadingMenuDataStorageLayout();
    BGSLocation* currentLocation;
    bool unk18;
};
static_assert(sizeof(LoadingMenuDataStorageLayout) == 32, "community represented size");
static_assert(offsetof(LoadingMenuDataStorageLayout, currentLocation) == 16, "currentLocation offset");
static_assert(offsetof(LoadingMenuDataStorageLayout, unk18) == 24, "unk18 offset");
}
