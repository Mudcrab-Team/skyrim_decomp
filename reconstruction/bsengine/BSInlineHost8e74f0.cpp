// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8e74f0, reference: GUESS(low) STANDIN
// 0x8e74f0 BSInlineHost8e74f0::~BSInlineHost8e74f0
#include "BSInlineHost8e74f0.h"
BSInlineHost8e74f0::~BSInlineHost8e74f0() {
    if (reference) reference->DecRefCount();
}
