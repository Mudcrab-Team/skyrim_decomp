// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/C/ClickHandler.h; GPL-3.0.
// ClickHandler: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ClickHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/MenuEventHandlerLayout.h"

namespace ResearchLayouts {
class ClickHandlerLayout : public MenuEventHandlerLayout {
public:
    virtual ~ClickHandlerLayout();
};
static_assert(sizeof(ClickHandlerLayout) == 16, "community represented size");
}
