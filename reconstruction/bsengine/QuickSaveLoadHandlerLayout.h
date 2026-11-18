// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/Q/QuickSaveLoadHandler.h; GPL-3.0.
// QuickSaveLoadHandler: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// QuickSaveLoadHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/MenuEventHandlerLayout.h"

namespace ResearchLayouts {
class QuickSaveLoadHandlerLayout : public MenuEventHandlerLayout {
public:
    virtual ~QuickSaveLoadHandlerLayout();
};
static_assert(sizeof(QuickSaveLoadHandlerLayout) == 16, "community represented size");
}
