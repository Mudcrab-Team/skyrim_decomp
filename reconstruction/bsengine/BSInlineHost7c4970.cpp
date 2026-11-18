// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost7c4970, reference: GUESS(low) STANDIN
// 0x7c4970 BSInlineHost7c4970::~BSInlineHost7c4970
#include "BSInlineHost7c4970.h"
BSInlineHost7c4970::~BSInlineHost7c4970() {
    if (reference) reference->DecRefCount();
}
