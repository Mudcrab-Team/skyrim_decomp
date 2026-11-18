// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8c18e0, reference: GUESS(low) STANDIN
// 0x8c18e0 BSInlineHost8c18e0::~BSInlineHost8c18e0
#include "BSInlineHost8c18e0.h"
BSInlineHost8c18e0::~BSInlineHost8c18e0() {
    if (reference) reference->DecRefCount();
}
