// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost21ecb0, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x21ecb0 BSInlineHost21ecb0::~BSInlineHost21ecb0
#include "BSInlineHost21ecb0.h"
BSInlineHost21ecb0::~BSInlineHost21ecb0() {
    if (reference) reference->DecRefCount();
}
