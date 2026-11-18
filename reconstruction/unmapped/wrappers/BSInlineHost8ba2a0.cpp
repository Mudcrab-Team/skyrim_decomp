// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8ba2a0, reference: GUESS(low) STANDIN
// 0x8ba2a0 BSInlineHost8ba2a0::~BSInlineHost8ba2a0
#include "BSInlineHost8ba2a0.h"
BSInlineHost8ba2a0::~BSInlineHost8ba2a0() {
    if (reference) reference->DecRefCount();
}
