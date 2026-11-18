// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostfb46f0, reference: GUESS(low) STANDIN
// 0xfb46f0 BSInlineHostfb46f0::~BSInlineHostfb46f0
#include "BSInlineHostfb46f0.h"
BSInlineHostfb46f0::~BSInlineHostfb46f0() {
    if (reference) reference->DecRefCount();
}
