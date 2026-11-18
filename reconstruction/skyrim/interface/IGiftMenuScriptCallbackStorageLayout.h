// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/I/IGiftMenuScriptCallback.h; GPL-3.0.
// IGiftMenuScriptCallback: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// IGiftMenuScriptCallbackLayout: GUESS(medium) STANDIN; represented layout type names
// Adapted from published p106 represented declaration reconstruction/bsengine/IGiftMenuScriptCallbackLayout.h.
// IGiftMenuScriptCallbackStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>
#include "../../bscore/BSIntrusiveRefCountedStorageLayout.h"

namespace ResearchLayouts {
class IGiftMenuScriptCallbackStorageLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~IGiftMenuScriptCallbackStorageLayout();
};
static_assert(sizeof(IGiftMenuScriptCallbackStorageLayout) == 16, "community represented size");
}
