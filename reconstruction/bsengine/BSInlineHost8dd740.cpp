// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8dd740, reference: GUESS(low) STANDIN
// 0x8dd740 BSInlineHost8dd740::~BSInlineHost8dd740
#include "BSInlineHost8dd740.h"
BSInlineHost8dd740::~BSInlineHost8dd740() {
    if (reference) reference->DecRefCount();
}
