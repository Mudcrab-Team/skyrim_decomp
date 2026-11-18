// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost321bb0, reference: GUESS(low) STANDIN
// 0x321bb0 BSInlineHost321bb0::~BSInlineHost321bb0
#include "BSInlineHost321bb0.h"
BSInlineHost321bb0::~BSInlineHost321bb0() {
    if (reference) reference->DecRefCount();
}
