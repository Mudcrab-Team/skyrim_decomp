// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf67020, reference: GUESS(low) STANDIN
// 0xf67020 BSInlineHostf67020::~BSInlineHostf67020
#include "BSInlineHostf67020.h"
BSInlineHostf67020::~BSInlineHostf67020() {
    if (reference) reference->DecRefCount();
}
