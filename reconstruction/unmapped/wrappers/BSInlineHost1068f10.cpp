// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost1068f10, reference: GUESS(low) STANDIN
// 0x1068f10 BSInlineHost1068f10::~BSInlineHost1068f10
#include "BSInlineHost1068f10.h"
BSInlineHost1068f10::~BSInlineHost1068f10() {
    if (reference) reference->DecRefCount();
}
