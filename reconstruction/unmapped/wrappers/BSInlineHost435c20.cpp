// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost435c20, reference: GUESS(low) STANDIN
// 0x435c20 BSInlineHost435c20::~BSInlineHost435c20
#include "BSInlineHost435c20.h"
BSInlineHost435c20::~BSInlineHost435c20() {
    if (reference) reference->DecRefCount();
}
