// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8788f0, reference: GUESS(low) STANDIN
// 0x8788f0 BSInlineHost8788f0::~BSInlineHost8788f0
#include "BSInlineHost8788f0.h"
BSInlineHost8788f0::~BSInlineHost8788f0() {
    if (reference) reference->DecRefCount();
}
