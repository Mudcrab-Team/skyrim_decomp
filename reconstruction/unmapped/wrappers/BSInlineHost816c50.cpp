// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost816c50, reference: GUESS(low) STANDIN
// 0x816c50 BSInlineHost816c50::~BSInlineHost816c50
#include "BSInlineHost816c50.h"
BSInlineHost816c50::~BSInlineHost816c50() {
    if (reference) reference->DecRefCount();
}
