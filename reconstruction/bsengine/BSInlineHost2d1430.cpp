// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2d1430, reference: GUESS(low) STANDIN
// 0x2d1430 BSInlineHost2d1430::~BSInlineHost2d1430
#include "BSInlineHost2d1430.h"
BSInlineHost2d1430::~BSInlineHost2d1430() {
    if (reference) reference->DecRefCount();
}
