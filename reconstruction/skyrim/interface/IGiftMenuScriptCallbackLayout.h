// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/I/IGiftMenuScriptCallback.h; GPL-3.0.
// IGiftMenuScriptCallback: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// IGiftMenuScriptCallbackLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSIntrusiveRefCountedLayout.h"

namespace ResearchLayouts {
class IGiftMenuScriptCallbackLayout : public BSIntrusiveRefCountedLayout {
public:
    virtual ~IGiftMenuScriptCallbackLayout();
};
static_assert(sizeof(IGiftMenuScriptCallbackLayout) == 16, "community represented size");
}
