// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost10870c0, reference: GUESS(low) STANDIN
// 0x10870c0 BSInlineHost10870c0::~BSInlineHost10870c0
#include "BSInlineHost10870c0.h"
BSInlineHost10870c0::~BSInlineHost10870c0() {
    if (reference) reference->DecRefCount();
}
