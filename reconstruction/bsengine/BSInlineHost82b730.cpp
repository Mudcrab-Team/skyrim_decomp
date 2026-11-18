// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost82b730, reference: GUESS(low) STANDIN
// 0x82b730 BSInlineHost82b730::~BSInlineHost82b730
#include "BSInlineHost82b730.h"
BSInlineHost82b730::~BSInlineHost82b730() {
    if (reference) reference->DecRefCount();
}
