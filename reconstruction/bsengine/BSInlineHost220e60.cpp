// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost220e60, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x220e60 BSInlineHost220e60::~BSInlineHost220e60
#include "BSInlineHost220e60.h"
BSInlineHost220e60::~BSInlineHost220e60() {
    if (reference) reference->DecRefCount();
}
