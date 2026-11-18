// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf9a080, reference: GUESS(low) STANDIN
// 0xf9a080 BSInlineHostf9a080::~BSInlineHostf9a080
#include "BSInlineHostf9a080.h"
BSInlineHostf9a080::~BSInlineHostf9a080() {
    if (reference) reference->DecRefCount();
}
