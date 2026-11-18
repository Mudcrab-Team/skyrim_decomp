// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostefce10, reference: GUESS(low) STANDIN
// 0xefce10 BSInlineHostefce10::~BSInlineHostefce10
#include "BSInlineHostefce10.h"
BSInlineHostefce10::~BSInlineHostefce10() {
    if (reference) reference->DecRefCount();
}
