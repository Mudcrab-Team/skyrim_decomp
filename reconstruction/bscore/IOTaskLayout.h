// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/I/IOTask.h; GPL-3.0.
// IOTask: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// IOTaskLayout: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "bscore/BSTaskLayout.h"

namespace ResearchLayouts {
class IOTaskLayout : public BSTaskLayout {
public:
    virtual ~IOTaskLayout();
};
static_assert(sizeof(IOTaskLayout) == 24, "community represented size");
}
