// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost202320, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x202320 BSInlineHost202320::~BSInlineHost202320
#include "BSInlineHost202320.h"
BSInlineHost202320::~BSInlineHost202320() {
    if (reference) reference->DecRefCount();
}
