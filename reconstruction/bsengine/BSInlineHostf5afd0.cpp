// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf5afd0, reference: GUESS(low) STANDIN
// 0xf5afd0 BSInlineHostf5afd0::~BSInlineHostf5afd0
#include "BSInlineHostf5afd0.h"
BSInlineHostf5afd0::~BSInlineHostf5afd0() {
    if (reference) reference->DecRefCount();
}
