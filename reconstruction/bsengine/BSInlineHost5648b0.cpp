// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost5648b0, reference: GUESS(low) STANDIN
// 0x5648b0 BSInlineHost5648b0::~BSInlineHost5648b0
#include "BSInlineHost5648b0.h"
BSInlineHost5648b0::~BSInlineHost5648b0() {
    if (reference) reference->DecRefCount();
}
