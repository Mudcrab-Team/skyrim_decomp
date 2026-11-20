// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost4d30e0, reference: GUESS(low) STANDIN
// 0x4d30e0 BSInlineHost4d30e0::~BSInlineHost4d30e0
#include "BSInlineHost4d30e0.h"
BSInlineHost4d30e0::~BSInlineHost4d30e0() {
    if (reference) reference->DecRefCount();
}
