// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost4b85d0, reference: GUESS(low) STANDIN
// 0x4b85d0 BSInlineHost4b85d0::~BSInlineHost4b85d0
#include "BSInlineHost4b85d0.h"
BSInlineHost4b85d0::~BSInlineHost4b85d0() {
    if (reference) reference->DecRefCount();
}
