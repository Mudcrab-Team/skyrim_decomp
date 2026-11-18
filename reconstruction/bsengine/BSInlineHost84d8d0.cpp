// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost84d8d0, reference: GUESS(low) STANDIN
// 0x84d8d0 BSInlineHost84d8d0::~BSInlineHost84d8d0
#include "BSInlineHost84d8d0.h"
BSInlineHost84d8d0::~BSInlineHost84d8d0() {
    if (reference) reference->DecRefCount();
}
