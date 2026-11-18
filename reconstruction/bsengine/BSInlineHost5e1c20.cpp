// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost5e1c20, reference: GUESS(low) STANDIN
// 0x5e1c20 BSInlineHost5e1c20::~BSInlineHost5e1c20
#include "BSInlineHost5e1c20.h"
BSInlineHost5e1c20::~BSInlineHost5e1c20() {
    if (reference) reference->DecRefCount();
}
