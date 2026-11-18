// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8c18b0, reference: GUESS(low) STANDIN
// 0x8c18b0 BSInlineHost8c18b0::~BSInlineHost8c18b0
#include "BSInlineHost8c18b0.h"
BSInlineHost8c18b0::~BSInlineHost8c18b0() {
    if (reference) reference->DecRefCount();
}
