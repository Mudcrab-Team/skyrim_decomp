// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost1534b20, reference: GUESS(low) STANDIN
// 0x1534b20 BSInlineHost1534b20::~BSInlineHost1534b20
#include "BSInlineHost1534b20.h"
BSInlineHost1534b20::~BSInlineHost1534b20() {
    if (reference) reference->DecRefCount();
}
