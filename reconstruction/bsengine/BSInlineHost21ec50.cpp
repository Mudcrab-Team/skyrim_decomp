// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost21ec50, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x21ec50 BSInlineHost21ec50::~BSInlineHost21ec50
#include "BSInlineHost21ec50.h"
BSInlineHost21ec50::~BSInlineHost21ec50() {
    if (reference) reference->DecRefCount();
}
