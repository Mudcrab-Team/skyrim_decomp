// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost71c3c0, reference: GUESS(low) STANDIN
// 0x71c3c0 BSInlineHost71c3c0::~BSInlineHost71c3c0
#include "BSInlineHost71c3c0.h"
BSInlineHost71c3c0::~BSInlineHost71c3c0() {
    if (reference) reference->DecRefCount();
}
