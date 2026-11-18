// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2a8b40, reference: GUESS(low) STANDIN
// 0x2a8b40 BSInlineHost2a8b40::~BSInlineHost2a8b40
#include "BSInlineHost2a8b40.h"
BSInlineHost2a8b40::~BSInlineHost2a8b40() {
    if (reference) reference->DecRefCount();
}
