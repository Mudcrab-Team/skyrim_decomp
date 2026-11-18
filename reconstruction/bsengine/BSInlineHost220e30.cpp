// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost220e30, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x220e30 BSInlineHost220e30::~BSInlineHost220e30
#include "BSInlineHost220e30.h"
BSInlineHost220e30::~BSInlineHost220e30() {
    if (reference) reference->DecRefCount();
}
