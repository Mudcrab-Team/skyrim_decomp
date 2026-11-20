// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost2023b0, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x2023b0 BSInlineHost2023b0::~BSInlineHost2023b0
#include "BSInlineHost2023b0.h"
BSInlineHost2023b0::~BSInlineHost2023b0() {
    if (reference) reference->DecRefCount();
}
