// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost4c0150, reference: GUESS(low) STANDIN
// 0x4c0150 BSInlineHost4c0150::~BSInlineHost4c0150
#include "BSInlineHost4c0150.h"
BSInlineHost4c0150::~BSInlineHost4c0150() {
    if (reference) reference->DecRefCount();
}
