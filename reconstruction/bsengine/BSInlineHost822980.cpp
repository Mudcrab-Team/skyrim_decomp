// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost822980, reference: GUESS(low) STANDIN
// 0x822980 BSInlineHost822980::~BSInlineHost822980
#include "BSInlineHost822980.h"
BSInlineHost822980::~BSInlineHost822980() {
    if (reference) reference->DecRefCount();
}
