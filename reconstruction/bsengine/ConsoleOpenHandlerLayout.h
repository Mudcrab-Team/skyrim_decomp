// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/C/ConsoleOpenHandler.h; GPL-3.0.
// ConsoleOpenHandler: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ConsoleOpenHandlerLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bsengine/MenuEventHandlerLayout.h"

namespace ResearchLayouts {
class ConsoleOpenHandlerLayout : public MenuEventHandlerLayout {
public:
    virtual ~ConsoleOpenHandlerLayout();
};
static_assert(sizeof(ConsoleOpenHandlerLayout) == 16, "community represented size");
}
