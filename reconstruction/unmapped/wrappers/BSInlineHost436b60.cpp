// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost436b60, reference: GUESS(low) STANDIN
// 0x436b60 BSInlineHost436b60::~BSInlineHost436b60
#include "BSInlineHost436b60.h"
BSInlineHost436b60::~BSInlineHost436b60() {
    if (reference) reference->DecRefCount();
}
