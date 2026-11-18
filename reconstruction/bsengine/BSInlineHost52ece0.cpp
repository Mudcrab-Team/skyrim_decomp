// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost52ece0, reference: GUESS(low) STANDIN
// 0x52ece0 BSInlineHost52ece0::~BSInlineHost52ece0
#include "BSInlineHost52ece0.h"
BSInlineHost52ece0::~BSInlineHost52ece0() {
    if (reference) reference->DecRefCount();
}
