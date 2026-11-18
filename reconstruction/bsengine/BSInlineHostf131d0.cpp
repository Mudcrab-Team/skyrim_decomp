// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf131d0, reference: GUESS(low) STANDIN
// 0xf131d0 BSInlineHostf131d0::~BSInlineHostf131d0
#include "BSInlineHostf131d0.h"
BSInlineHostf131d0::~BSInlineHostf131d0() {
    if (reference) reference->DecRefCount();
}
