// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf622b0, reference: GUESS(low) STANDIN
// 0xf622b0 BSInlineHostf622b0::~BSInlineHostf622b0
#include "BSInlineHostf622b0.h"
BSInlineHostf622b0::~BSInlineHostf622b0() {
    if (reference) reference->DecRefCount();
}
