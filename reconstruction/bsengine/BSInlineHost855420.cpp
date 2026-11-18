// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost855420, reference: GUESS(low) STANDIN
// 0x855420 BSInlineHost855420::~BSInlineHost855420
#include "BSInlineHost855420.h"
BSInlineHost855420::~BSInlineHost855420() {
    if (reference) reference->DecRefCount();
}
