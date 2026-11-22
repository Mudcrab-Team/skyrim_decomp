// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/C/ConsoleOpenHandler.h; GPL-3.0.
// ConsoleOpenHandler: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ConsoleOpenHandlerLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/ConsoleOpenHandlerLayout.h.
// ConsoleOpenHandlerStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "skyrim/interface/MenuEventHandlerStorageLayout.h"

namespace ResearchLayouts {
class ConsoleOpenHandlerStorageLayout : public MenuEventHandlerStorageLayout {
public:
    virtual ~ConsoleOpenHandlerStorageLayout();
};
static_assert(sizeof(ConsoleOpenHandlerStorageLayout) == 16, "community represented size");
}
