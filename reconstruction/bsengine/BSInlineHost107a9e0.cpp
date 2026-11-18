// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost107a9e0, reference: GUESS(low) STANDIN
// 0x107a9e0 BSInlineHost107a9e0::~BSInlineHost107a9e0
#include "BSInlineHost107a9e0.h"
BSInlineHost107a9e0::~BSInlineHost107a9e0() {
    if (reference) reference->DecRefCount();
}
