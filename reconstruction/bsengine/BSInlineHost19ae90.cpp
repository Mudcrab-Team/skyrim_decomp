// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost19ae90, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x19ae90 BSInlineHost19ae90::~BSInlineHost19ae90
#include "BSInlineHost19ae90.h"
BSInlineHost19ae90::~BSInlineHost19ae90() {
    if (reference) reference->DecRefCount();
}
