// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost6bac20, reference: GUESS(low) STANDIN
// 0x6bac20 BSInlineHost6bac20::~BSInlineHost6bac20
#include "BSInlineHost6bac20.h"
BSInlineHost6bac20::~BSInlineHost6bac20() {
    if (reference) reference->DecRefCount();
}
