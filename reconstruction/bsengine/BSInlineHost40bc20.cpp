// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost40bc20, reference: GUESS(low) STANDIN
// 0x40bc20 BSInlineHost40bc20::~BSInlineHost40bc20
#include "BSInlineHost40bc20.h"
BSInlineHost40bc20::~BSInlineHost40bc20() {
    if (reference) reference->DecRefCount();
}
