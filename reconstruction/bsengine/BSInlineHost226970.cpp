// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost226970, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x226970 BSInlineHost226970::~BSInlineHost226970
#include "BSInlineHost226970.h"
BSInlineHost226970::~BSInlineHost226970() {
    if (reference) reference->DecRefCount();
}
