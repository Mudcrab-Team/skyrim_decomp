// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2d1400, reference: GUESS(low) STANDIN
// 0x2d1400 BSInlineHost2d1400::~BSInlineHost2d1400
#include "BSInlineHost2d1400.h"
BSInlineHost2d1400::~BSInlineHost2d1400() {
    if (reference) reference->DecRefCount();
}
