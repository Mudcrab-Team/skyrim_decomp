// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost8b6780, reference: GUESS(low) STANDIN
// 0x8b6780 BSInlineHost8b6780::~BSInlineHost8b6780
#include "BSInlineHost8b6780.h"
BSInlineHost8b6780::~BSInlineHost8b6780() {
    if (reference) reference->DecRefCount();
}
