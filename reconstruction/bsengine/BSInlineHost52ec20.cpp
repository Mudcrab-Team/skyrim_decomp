// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost52ec20, reference: GUESS(low) STANDIN
// 0x52ec20 BSInlineHost52ec20::~BSInlineHost52ec20
#include "BSInlineHost52ec20.h"
BSInlineHost52ec20::~BSInlineHost52ec20() {
    if (reference) reference->DecRefCount();
}
