// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostfcda20, reference: GUESS(low) STANDIN
// 0xfcda20 BSInlineHostfcda20::~BSInlineHostfcda20
#include "BSInlineHostfcda20.h"
BSInlineHostfcda20::~BSInlineHostfcda20() {
    if (reference) reference->DecRefCount();
}
