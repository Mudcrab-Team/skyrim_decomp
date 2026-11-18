// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost89c8c0, reference: GUESS(low) STANDIN
// 0x89c8c0 BSInlineHost89c8c0::~BSInlineHost89c8c0
#include "BSInlineHost89c8c0.h"
BSInlineHost89c8c0::~BSInlineHost89c8c0() {
    if (reference) reference->DecRefCount();
}
