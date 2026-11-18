// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost71c390, reference: GUESS(low) STANDIN
// 0x71c390 BSInlineHost71c390::~BSInlineHost71c390
#include "BSInlineHost71c390.h"
BSInlineHost71c390::~BSInlineHost71c390() {
    if (reference) reference->DecRefCount();
}
