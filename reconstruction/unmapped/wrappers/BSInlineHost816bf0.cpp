// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost816bf0, reference: GUESS(low) STANDIN
// 0x816bf0 BSInlineHost816bf0::~BSInlineHost816bf0
#include "BSInlineHost816bf0.h"
BSInlineHost816bf0::~BSInlineHost816bf0() {
    if (reference) reference->DecRefCount();
}
