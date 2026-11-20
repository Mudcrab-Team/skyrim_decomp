// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/L/LoadingMenuData.h; GPL-3.0.
// LoadingMenuData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// LoadingMenuDataLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsscaleform/IUIMessageDataLayout.h"

namespace ResearchLayouts {
class BGSLocation;
class LoadingMenuDataLayout : public IUIMessageDataLayout {
public:
    virtual ~LoadingMenuDataLayout();
    BGSLocation* currentLocation;
    bool unk18;
};
static_assert(sizeof(LoadingMenuDataLayout) == 32, "community represented size");
static_assert(offsetof(LoadingMenuDataLayout, currentLocation) == 16, "currentLocation offset");
static_assert(offsetof(LoadingMenuDataLayout, unk18) == 24, "unk18 offset");
}
