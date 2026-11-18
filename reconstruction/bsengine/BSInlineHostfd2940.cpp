// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Body origin: original reconstruction; shared reference types carry their attribution.
// BSInlineHostfd2940, reference: GUESS(low) STANDIN
// 0xfd2940 BSInlineHostfd2940::~BSInlineHostfd2940
#include "BSInlineHostfd2940.h"
BSInlineHostfd2940::~BSInlineHostfd2940() {
    if (reference) reference->DecRefCount();
}
