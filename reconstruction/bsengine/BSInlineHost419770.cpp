// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost419770, reference: GUESS(low) STANDIN
// 0x419770 BSInlineHost419770::~BSInlineHost419770
#include "BSInlineHost419770.h"
BSInlineHost419770::~BSInlineHost419770() {
    if (reference) reference->DecRefCount();
}
