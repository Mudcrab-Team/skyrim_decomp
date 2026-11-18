// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost15754d0, reference: GUESS(low) STANDIN
// 0x15754d0 BSInlineHost15754d0::~BSInlineHost15754d0
#include "BSInlineHost15754d0.h"
BSInlineHost15754d0::~BSInlineHost15754d0() {
    if (reference) reference->DecRefCount();
}
