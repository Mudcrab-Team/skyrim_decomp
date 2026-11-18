// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost50d8a0, reference: GUESS(low) STANDIN
// 0x50d8a0 BSInlineHost50d8a0::~BSInlineHost50d8a0
#include "BSInlineHost50d8a0.h"
BSInlineHost50d8a0::~BSInlineHost50d8a0() {
    if (reference) reference->DecRefCount();
}
