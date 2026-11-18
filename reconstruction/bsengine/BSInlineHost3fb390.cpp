// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost3fb390, reference: GUESS(low) STANDIN
// 0x3fb390 BSInlineHost3fb390::~BSInlineHost3fb390
#include "BSInlineHost3fb390.h"
BSInlineHost3fb390::~BSInlineHost3fb390() {
    if (reference) reference->DecRefCount();
}
