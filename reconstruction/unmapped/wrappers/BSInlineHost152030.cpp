// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost152030, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x152030 BSInlineHost152030::~BSInlineHost152030
#include "BSInlineHost152030.h"
BSInlineHost152030::~BSInlineHost152030() {
    if (reference) reference->DecRefCount();
}
