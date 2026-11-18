// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost14ed280, reference: GUESS(low) STANDIN
// 0x14ed280 BSInlineHost14ed280::~BSInlineHost14ed280
#include "BSInlineHost14ed280.h"
BSInlineHost14ed280::~BSInlineHost14ed280() {
    if (reference) reference->DecRefCount();
}
