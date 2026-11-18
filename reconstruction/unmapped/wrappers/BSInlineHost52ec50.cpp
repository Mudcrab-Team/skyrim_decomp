// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost52ec50, reference: GUESS(low) STANDIN
// 0x52ec50 BSInlineHost52ec50::~BSInlineHost52ec50
#include "BSInlineHost52ec50.h"
BSInlineHost52ec50::~BSInlineHost52ec50() {
    if (reference) reference->DecRefCount();
}
