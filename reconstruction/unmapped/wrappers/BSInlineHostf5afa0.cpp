// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf5afa0, reference: GUESS(low) STANDIN
// 0xf5afa0 BSInlineHostf5afa0::~BSInlineHostf5afa0
#include "BSInlineHostf5afa0.h"
BSInlineHostf5afa0::~BSInlineHostf5afa0() {
    if (reference) reference->DecRefCount();
}
