// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8727e0, reference: GUESS(low) STANDIN
// 0x8727e0 BSInlineHost8727e0::~BSInlineHost8727e0
#include "BSInlineHost8727e0.h"
BSInlineHost8727e0::~BSInlineHost8727e0() {
    if (reference) reference->DecRefCount();
}
