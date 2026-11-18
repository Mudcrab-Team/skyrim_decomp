// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf9c070, reference: GUESS(low) STANDIN
// 0xf9c070 BSInlineHostf9c070::~BSInlineHostf9c070
#include "BSInlineHostf9c070.h"
BSInlineHostf9c070::~BSInlineHostf9c070() {
    if (reference) reference->DecRefCount();
}
