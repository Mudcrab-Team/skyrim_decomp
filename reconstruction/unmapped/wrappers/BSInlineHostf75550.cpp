// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf75550, reference: GUESS(low) STANDIN
// 0xf75550 BSInlineHostf75550::~BSInlineHostf75550
#include "BSInlineHostf75550.h"
BSInlineHostf75550::~BSInlineHostf75550() {
    if (reference) reference->DecRefCount();
}
