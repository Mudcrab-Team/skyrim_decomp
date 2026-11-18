// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost5c6430, reference: GUESS(low) STANDIN
// 0x5c6430 BSInlineHost5c6430::~BSInlineHost5c6430
#include "BSInlineHost5c6430.h"
BSInlineHost5c6430::~BSInlineHost5c6430() {
    if (reference) reference->DecRefCount();
}
