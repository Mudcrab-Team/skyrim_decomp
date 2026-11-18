// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost816c20, reference: GUESS(low) STANDIN
// 0x816c20 BSInlineHost816c20::~BSInlineHost816c20
#include "BSInlineHost816c20.h"
BSInlineHost816c20::~BSInlineHost816c20() {
    if (reference) reference->DecRefCount();
}
