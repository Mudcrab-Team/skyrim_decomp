// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost52ec80, reference: GUESS(low) STANDIN
// 0x52ec80 BSInlineHost52ec80::~BSInlineHost52ec80
#include "BSInlineHost52ec80.h"
BSInlineHost52ec80::~BSInlineHost52ec80() {
    if (reference) reference->DecRefCount();
}
