// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost7686b0, reference: GUESS(low) STANDIN
// 0x7686b0 BSInlineHost7686b0::~BSInlineHost7686b0
#include "BSInlineHost7686b0.h"
BSInlineHost7686b0::~BSInlineHost7686b0() {
    if (reference) reference->DecRefCount();
}
