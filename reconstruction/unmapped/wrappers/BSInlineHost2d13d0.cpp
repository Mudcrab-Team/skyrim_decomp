// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2d13d0, reference: GUESS(low) STANDIN
// 0x2d13d0 BSInlineHost2d13d0::~BSInlineHost2d13d0
#include "BSInlineHost2d13d0.h"
BSInlineHost2d13d0::~BSInlineHost2d13d0() {
    if (reference) reference->DecRefCount();
}
