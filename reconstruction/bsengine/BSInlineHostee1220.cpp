// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostee1220, reference: GUESS(low) STANDIN
// 0xee1220 BSInlineHostee1220::~BSInlineHostee1220
#include "BSInlineHostee1220.h"
BSInlineHostee1220::~BSInlineHostee1220() {
    if (reference) reference->DecRefCount();
}
