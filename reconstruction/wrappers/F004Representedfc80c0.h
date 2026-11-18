// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Representedfc80c0, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/QueuedFileLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/Q/QueuedFile.h; GPL-3.0.
// QueuedFile: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// F004Representedfc80c0: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/IOTaskLayout.h"
#include "../f004support/BSFixedStringLayout.h"

namespace ResearchLayouts {
class F004Representedfc80c0;
class F004Representedfc80c0 : public IOTaskLayout {
public:
    virtual ~F004Representedfc80c0();
    std::uint64_t unk18;
    NiPointerLayout<F004Representedfc80c0> parent;
    std::uint64_t children;
    std::uint64_t unk30;
};
static_assert(sizeof(F004Representedfc80c0) == 56, "community represented size");
static_assert(offsetof(F004Representedfc80c0, unk18) == 24, "unk18 offset");
static_assert(offsetof(F004Representedfc80c0, parent) == 32, "parent offset");
static_assert(offsetof(F004Representedfc80c0, children) == 40, "children offset");
static_assert(offsetof(F004Representedfc80c0, unk30) == 48, "unk30 offset");
}
