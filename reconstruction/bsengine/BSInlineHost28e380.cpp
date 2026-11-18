// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost28e380, reference: GUESS(low) STANDIN
// 0x28e380 BSInlineHost28e380::~BSInlineHost28e380
#include "BSInlineHost28e380.h"
BSInlineHost28e380::~BSInlineHost28e380() {
    if (reference) reference->DecRefCount();
}
