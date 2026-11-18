// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost1054e00, reference: GUESS(low) STANDIN
// 0x1054e00 BSInlineHost1054e00::~BSInlineHost1054e00
#include "BSInlineHost1054e00.h"
BSInlineHost1054e00::~BSInlineHost1054e00() {
    if (reference) reference->DecRefCount();
}
