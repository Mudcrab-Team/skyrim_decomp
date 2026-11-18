// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost71c360, reference: GUESS(low) STANDIN
// 0x71c360 BSInlineHost71c360::~BSInlineHost71c360
#include "BSInlineHost71c360.h"
BSInlineHost71c360::~BSInlineHost71c360() {
    if (reference) reference->DecRefCount();
}
