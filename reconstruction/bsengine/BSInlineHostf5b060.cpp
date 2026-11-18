// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf5b060, reference: GUESS(low) STANDIN
// 0xf5b060 BSInlineHostf5b060::~BSInlineHostf5b060
#include "BSInlineHostf5b060.h"
BSInlineHostf5b060::~BSInlineHostf5b060() {
    if (reference) reference->DecRefCount();
}
