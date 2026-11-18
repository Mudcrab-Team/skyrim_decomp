// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf0a6f0, reference: GUESS(low) STANDIN
// 0xf0a6f0 BSInlineHostf0a6f0::~BSInlineHostf0a6f0
#include "BSInlineHostf0a6f0.h"
BSInlineHostf0a6f0::~BSInlineHostf0a6f0() {
    if (reference) reference->DecRefCount();
}
