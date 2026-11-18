// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost1b2940, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x1b2940 BSInlineHost1b2940::~BSInlineHost1b2940
#include "BSInlineHost1b2940.h"
BSInlineHost1b2940::~BSInlineHost1b2940() {
    if (reference) reference->DecRefCount();
}
