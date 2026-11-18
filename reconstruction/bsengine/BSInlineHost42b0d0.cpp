// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost42b0d0, reference: GUESS(low) STANDIN
// 0x42b0d0 BSInlineHost42b0d0::~BSInlineHost42b0d0
#include "BSInlineHost42b0d0.h"
BSInlineHost42b0d0::~BSInlineHost42b0d0() {
    if (reference) reference->DecRefCount();
}
