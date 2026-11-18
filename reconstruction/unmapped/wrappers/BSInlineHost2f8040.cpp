// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2f8040, reference: GUESS(low) STANDIN
// 0x2f8040 BSInlineHost2f8040::~BSInlineHost2f8040
#include "BSInlineHost2f8040.h"
BSInlineHost2f8040::~BSInlineHost2f8040() {
    if (reference) reference->DecRefCount();
}
