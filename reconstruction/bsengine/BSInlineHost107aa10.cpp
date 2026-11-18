// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost107aa10, reference: GUESS(low) STANDIN
// 0x107aa10 BSInlineHost107aa10::~BSInlineHost107aa10
#include "BSInlineHost107aa10.h"
BSInlineHost107aa10::~BSInlineHost107aa10() {
    if (reference) reference->DecRefCount();
}
