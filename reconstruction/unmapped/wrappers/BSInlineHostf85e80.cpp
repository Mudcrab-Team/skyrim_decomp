// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf85e80, reference: GUESS(low) STANDIN
// 0xf85e80 BSInlineHostf85e80::~BSInlineHostf85e80
#include "BSInlineHostf85e80.h"
BSInlineHostf85e80::~BSInlineHostf85e80() {
    if (reference) reference->DecRefCount();
}
