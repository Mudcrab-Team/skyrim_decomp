// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost202380, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x202380 BSInlineHost202380::~BSInlineHost202380
#include "BSInlineHost202380.h"
BSInlineHost202380::~BSInlineHost202380() {
    if (reference) reference->DecRefCount();
}
