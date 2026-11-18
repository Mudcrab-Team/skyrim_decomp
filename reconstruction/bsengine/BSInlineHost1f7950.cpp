// Source exposure: mixed (binary-analysis, community-headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost1f7950, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x1f7950 BSInlineHost1f7950::~BSInlineHost1f7950
#include "BSInlineHost1f7950.h"
BSInlineHost1f7950::~BSInlineHost1f7950() {
    if (reference) reference->DecRefCount();
}
