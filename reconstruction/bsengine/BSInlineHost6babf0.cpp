// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost6babf0, reference: GUESS(low) STANDIN
// 0x6babf0 BSInlineHost6babf0::~BSInlineHost6babf0
#include "BSInlineHost6babf0.h"
BSInlineHost6babf0::~BSInlineHost6babf0() {
    if (reference) reference->DecRefCount();
}
