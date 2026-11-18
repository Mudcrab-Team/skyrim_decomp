// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost768680, reference: GUESS(low) STANDIN
// 0x768680 BSInlineHost768680::~BSInlineHost768680
#include "BSInlineHost768680.h"
BSInlineHost768680::~BSInlineHost768680() {
    if (reference) reference->DecRefCount();
}
