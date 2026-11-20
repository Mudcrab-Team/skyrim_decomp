// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost3ffbb0, reference: GUESS(low) STANDIN
// 0x3ffbb0 BSInlineHost3ffbb0::~BSInlineHost3ffbb0
#include "BSInlineHost3ffbb0.h"
BSInlineHost3ffbb0::~BSInlineHost3ffbb0() {
    if (reference) reference->DecRefCount();
}
