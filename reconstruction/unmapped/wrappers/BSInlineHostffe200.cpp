// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostffe200, reference: GUESS(low) STANDIN
// 0xffe200 BSInlineHostffe200::~BSInlineHostffe200
#include "BSInlineHostffe200.h"
BSInlineHostffe200::~BSInlineHostffe200() {
    if (reference) reference->DecRefCount();
}
