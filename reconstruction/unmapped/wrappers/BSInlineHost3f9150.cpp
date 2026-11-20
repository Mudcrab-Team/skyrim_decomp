// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost3f9150, reference: GUESS(low) STANDIN
// 0x3f9150 BSInlineHost3f9150::~BSInlineHost3f9150
#include "BSInlineHost3f9150.h"
BSInlineHost3f9150::~BSInlineHost3f9150() {
    if (reference) reference->DecRefCount();
}
