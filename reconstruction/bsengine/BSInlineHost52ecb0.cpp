// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost52ecb0, reference: GUESS(low) STANDIN
// 0x52ecb0 BSInlineHost52ecb0::~BSInlineHost52ecb0
#include "BSInlineHost52ecb0.h"
BSInlineHost52ecb0::~BSInlineHost52ecb0() {
    if (reference) reference->DecRefCount();
}
