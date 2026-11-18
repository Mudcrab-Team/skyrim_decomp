// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost865cb0, reference: GUESS(low) STANDIN
// 0x865cb0 BSInlineHost865cb0::~BSInlineHost865cb0
#include "BSInlineHost865cb0.h"
BSInlineHost865cb0::~BSInlineHost865cb0() {
    if (reference) reference->DecRefCount();
}
