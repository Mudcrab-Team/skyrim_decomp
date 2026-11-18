// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost1b2970, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x1b2970 BSInlineHost1b2970::~BSInlineHost1b2970
#include "BSInlineHost1b2970.h"
BSInlineHost1b2970::~BSInlineHost1b2970() {
    if (reference) reference->DecRefCount();
}
