// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost202410, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x202410 BSInlineHost202410::~BSInlineHost202410
#include "BSInlineHost202410.h"
BSInlineHost202410::~BSInlineHost202410() {
    if (reference) reference->DecRefCount();
}
