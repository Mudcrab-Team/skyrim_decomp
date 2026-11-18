// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost966b90, reference: GUESS(low) STANDIN
// 0x966b90 BSInlineHost966b90::~BSInlineHost966b90
#include "BSInlineHost966b90.h"
BSInlineHost966b90::~BSInlineHost966b90() {
    if (reference) reference->DecRefCount();
}
