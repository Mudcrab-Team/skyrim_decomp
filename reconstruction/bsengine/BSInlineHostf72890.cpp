// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostf72890, reference: GUESS(low) STANDIN
// 0xf72890 BSInlineHostf72890::~BSInlineHostf72890
#include "BSInlineHostf72890.h"
BSInlineHostf72890::~BSInlineHostf72890() {
    if (reference) reference->DecRefCount();
}
