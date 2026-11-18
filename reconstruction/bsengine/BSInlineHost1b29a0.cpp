// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost1b29a0, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x1b29a0 BSInlineHost1b29a0::~BSInlineHost1b29a0
#include "BSInlineHost1b29a0.h"
BSInlineHost1b29a0::~BSInlineHost1b29a0() {
    if (reference) reference->DecRefCount();
}
