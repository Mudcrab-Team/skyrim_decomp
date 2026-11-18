// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost4b6490, reference: GUESS(low) STANDIN
// 0x4b6490 BSInlineHost4b6490::~BSInlineHost4b6490
#include "BSInlineHost4b6490.h"
BSInlineHost4b6490::~BSInlineHost4b6490() {
    if (reference) reference->DecRefCount();
}
