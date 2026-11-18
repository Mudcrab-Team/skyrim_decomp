// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost403190, reference: GUESS(low) STANDIN
// 0x403190 BSInlineHost403190::~BSInlineHost403190
#include "BSInlineHost403190.h"
BSInlineHost403190::~BSInlineHost403190() {
    if (reference) reference->DecRefCount();
}
