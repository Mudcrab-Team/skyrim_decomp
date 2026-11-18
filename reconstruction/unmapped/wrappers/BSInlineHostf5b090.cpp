// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf5b090, reference: GUESS(low) STANDIN
// 0xf5b090 BSInlineHostf5b090::~BSInlineHostf5b090
#include "BSInlineHostf5b090.h"
BSInlineHostf5b090::~BSInlineHostf5b090() {
    if (reference) reference->DecRefCount();
}
