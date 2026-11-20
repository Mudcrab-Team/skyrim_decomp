// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf7dd40, reference: GUESS(low) STANDIN
// 0xf7dd40 BSInlineHostf7dd40::~BSInlineHostf7dd40
#include "BSInlineHostf7dd40.h"
BSInlineHostf7dd40::~BSInlineHostf7dd40() {
    if (reference) reference->DecRefCount();
}
