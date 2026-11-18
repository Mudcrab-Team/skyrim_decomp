// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost40e9c0, reference: GUESS(low) STANDIN
// 0x40e9c0 BSInlineHost40e9c0::~BSInlineHost40e9c0
#include "BSInlineHost40e9c0.h"
BSInlineHost40e9c0::~BSInlineHost40e9c0() {
    if (reference) reference->DecRefCount();
}
