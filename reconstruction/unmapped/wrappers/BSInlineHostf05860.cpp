// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf05860, reference: GUESS(low) STANDIN
// 0xf05860 BSInlineHostf05860::~BSInlineHostf05860
#include "BSInlineHostf05860.h"
BSInlineHostf05860::~BSInlineHostf05860() {
    if (reference) reference->DecRefCount();
}
