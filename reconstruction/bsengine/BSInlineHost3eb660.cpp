// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost3eb660, reference: GUESS(low) STANDIN
// 0x3eb660 BSInlineHost3eb660::~BSInlineHost3eb660
#include "BSInlineHost3eb660.h"
BSInlineHost3eb660::~BSInlineHost3eb660() {
    if (reference) reference->DecRefCount();
}
