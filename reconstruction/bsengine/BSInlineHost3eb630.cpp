// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost3eb630, reference: GUESS(low) STANDIN
// 0x3eb630 BSInlineHost3eb630::~BSInlineHost3eb630
#include "BSInlineHost3eb630.h"
BSInlineHost3eb630::~BSInlineHost3eb630() {
    if (reference) reference->DecRefCount();
}
