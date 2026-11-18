// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// F004Represented19bf20, object: GUESS(low) STANDIN
// Declaration source: reconstruction/bsengine/IOTaskLayout.h (renamed complete represented declaration).
// Origin: rootless-represented-renamed-deleting-wrapper v3
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/I/IOTask.h; GPL-3.0.
// IOTask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// F004Represented19bf20: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/BSTaskLayout.h"

namespace ResearchLayouts {
class F004Represented19bf20 : public BSTaskLayout {
public:
    virtual ~F004Represented19bf20();
};
static_assert(sizeof(F004Represented19bf20) == 24, "community represented size");
}
