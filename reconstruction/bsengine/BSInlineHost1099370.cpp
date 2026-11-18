// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost1099370, reference: GUESS(low) STANDIN
// 0x1099370 BSInlineHost1099370::~BSInlineHost1099370
#include "BSInlineHost1099370.h"
BSInlineHost1099370::~BSInlineHost1099370() {
    if (reference) reference->DecRefCount();
}
