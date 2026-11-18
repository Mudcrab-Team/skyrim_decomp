// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost41cc30, reference: GUESS(low) STANDIN
// 0x41cc30 BSInlineHost41cc30::~BSInlineHost41cc30
#include "BSInlineHost41cc30.h"
BSInlineHost41cc30::~BSInlineHost41cc30() {
    if (reference) reference->DecRefCount();
}
