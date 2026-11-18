// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2a8b70, reference: GUESS(low) STANDIN
// 0x2a8b70 BSInlineHost2a8b70::~BSInlineHost2a8b70
#include "BSInlineHost2a8b70.h"
BSInlineHost2a8b70::~BSInlineHost2a8b70() {
    if (reference) reference->DecRefCount();
}
