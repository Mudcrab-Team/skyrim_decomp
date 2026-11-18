// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost816bc0, reference: GUESS(low) STANDIN
// 0x816bc0 BSInlineHost816bc0::~BSInlineHost816bc0
#include "BSInlineHost816bc0.h"
BSInlineHost816bc0::~BSInlineHost816bc0() {
    if (reference) reference->DecRefCount();
}
