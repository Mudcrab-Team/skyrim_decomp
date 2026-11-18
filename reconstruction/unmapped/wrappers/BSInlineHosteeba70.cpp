// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHosteeba70, reference: GUESS(low) STANDIN
// 0xeeba70 BSInlineHosteeba70::~BSInlineHosteeba70
#include "BSInlineHosteeba70.h"
BSInlineHosteeba70::~BSInlineHosteeba70() {
    if (reference) reference->DecRefCount();
}
