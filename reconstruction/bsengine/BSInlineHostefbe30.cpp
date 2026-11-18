// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostefbe30, reference: GUESS(low) STANDIN
// 0xefbe30 BSInlineHostefbe30::~BSInlineHostefbe30
#include "BSInlineHostefbe30.h"
BSInlineHostefbe30::~BSInlineHostefbe30() {
    if (reference) reference->DecRefCount();
}
