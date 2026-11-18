// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost41cc00, reference: GUESS(low) STANDIN
// 0x41cc00 BSInlineHost41cc00::~BSInlineHost41cc00
#include "BSInlineHost41cc00.h"
BSInlineHost41cc00::~BSInlineHost41cc00() {
    if (reference) reference->DecRefCount();
}
