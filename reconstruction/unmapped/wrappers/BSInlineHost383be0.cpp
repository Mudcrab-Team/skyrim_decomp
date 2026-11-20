// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost383be0, reference: GUESS(low) STANDIN
// 0x383be0 BSInlineHost383be0::~BSInlineHost383be0
#include "BSInlineHost383be0.h"
BSInlineHost383be0::~BSInlineHost383be0() {
    if (reference) reference->DecRefCount();
}
