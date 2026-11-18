// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf5b000, reference: GUESS(low) STANDIN
// 0xf5b000 BSInlineHostf5b000::~BSInlineHostf5b000
#include "BSInlineHostf5b000.h"
BSInlineHostf5b000::~BSInlineHostf5b000() {
    if (reference) reference->DecRefCount();
}
