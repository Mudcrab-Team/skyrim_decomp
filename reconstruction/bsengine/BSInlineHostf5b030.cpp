// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf5b030, reference: GUESS(low) STANDIN
// 0xf5b030 BSInlineHostf5b030::~BSInlineHostf5b030
#include "BSInlineHostf5b030.h"
BSInlineHostf5b030::~BSInlineHostf5b030() {
    if (reference) reference->DecRefCount();
}
