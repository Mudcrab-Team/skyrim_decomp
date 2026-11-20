// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost2f8070, reference: GUESS(low) STANDIN
// 0x2f8070 BSInlineHost2f8070::~BSInlineHost2f8070
#include "BSInlineHost2f8070.h"
BSInlineHost2f8070::~BSInlineHost2f8070() {
    if (reference) reference->DecRefCount();
}
