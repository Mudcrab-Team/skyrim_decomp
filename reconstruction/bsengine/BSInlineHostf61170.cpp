// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf61170, reference: GUESS(low) STANDIN
// 0xf61170 BSInlineHostf61170::~BSInlineHostf61170
#include "BSInlineHostf61170.h"
BSInlineHostf61170::~BSInlineHostf61170() {
    if (reference) reference->DecRefCount();
}
