// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2b5f90, reference: GUESS(low) STANDIN
// 0x2b5f90 BSInlineHost2b5f90::~BSInlineHost2b5f90
#include "BSInlineHost2b5f90.h"
BSInlineHost2b5f90::~BSInlineHost2b5f90() {
    if (reference) reference->DecRefCount();
}
