// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost12114f0, reference: GUESS(low) STANDIN
// 0x12114f0 BSInlineHost12114f0::~BSInlineHost12114f0
#include "BSInlineHost12114f0.h"
BSInlineHost12114f0::~BSInlineHost12114f0() {
    if (reference) reference->DecRefCount();
}
