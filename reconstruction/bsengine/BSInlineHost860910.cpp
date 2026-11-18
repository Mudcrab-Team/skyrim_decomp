// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost860910, reference: GUESS(low) STANDIN
// 0x860910 BSInlineHost860910::~BSInlineHost860910
#include "BSInlineHost860910.h"
BSInlineHost860910::~BSInlineHost860910() {
    if (reference) reference->DecRefCount();
}
