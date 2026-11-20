// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost21ec20, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x21ec20 BSInlineHost21ec20::~BSInlineHost21ec20
#include "BSInlineHost21ec20.h"
BSInlineHost21ec20::~BSInlineHost21ec20() {
    if (reference) reference->DecRefCount();
}
