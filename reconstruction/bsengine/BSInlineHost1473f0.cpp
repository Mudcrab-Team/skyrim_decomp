// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost1473f0, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x1473f0 BSInlineHost1473f0::~BSInlineHost1473f0
#include "BSInlineHost1473f0.h"
BSInlineHost1473f0::~BSInlineHost1473f0() {
    if (reference) reference->DecRefCount();
}
