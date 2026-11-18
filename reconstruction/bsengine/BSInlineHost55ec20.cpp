// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHost55ec20, reference: GUESS(low) STANDIN
// 0x55ec20 BSInlineHost55ec20::~BSInlineHost55ec20
#include "BSInlineHost55ec20.h"
BSInlineHost55ec20::~BSInlineHost55ec20() {
    if (reference) reference->DecRefCount();
}
