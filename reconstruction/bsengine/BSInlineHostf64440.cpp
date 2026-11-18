// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf64440, reference: GUESS(low) STANDIN
// 0xf64440 BSInlineHostf64440::~BSInlineHostf64440
#include "BSInlineHostf64440.h"
BSInlineHostf64440::~BSInlineHostf64440() {
    if (reference) reference->DecRefCount();
}
