// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost4411b0, reference: GUESS(low) STANDIN
// 0x4411b0 BSInlineHost4411b0::~BSInlineHost4411b0
#include "BSInlineHost4411b0.h"
BSInlineHost4411b0::~BSInlineHost4411b0() {
    if (reference) reference->DecRefCount();
}
