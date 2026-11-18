// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost40d230, reference: GUESS(low) STANDIN
// 0x40d230 BSInlineHost40d230::~BSInlineHost40d230
#include "BSInlineHost40d230.h"
BSInlineHost40d230::~BSInlineHost40d230() {
    if (reference) reference->DecRefCount();
}
