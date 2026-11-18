// Source exposure: mixed (binary-analysis, community-headers).
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostffe230, reference: GUESS(low) STANDIN
// 0xffe230 BSInlineHostffe230::~BSInlineHostffe230
#include "BSInlineHostffe230.h"
BSInlineHostffe230::~BSInlineHostffe230() {
    if (reference) reference->DecRefCount();
}
