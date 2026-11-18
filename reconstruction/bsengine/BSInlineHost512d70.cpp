// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost512d70, reference: GUESS(low) STANDIN
// 0x512d70 BSInlineHost512d70::~BSInlineHost512d70
#include "BSInlineHost512d70.h"
BSInlineHost512d70::~BSInlineHost512d70() {
    if (reference) reference->DecRefCount();
}
