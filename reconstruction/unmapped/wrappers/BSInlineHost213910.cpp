// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost213910, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x213910 BSInlineHost213910::~BSInlineHost213910
#include "BSInlineHost213910.h"
BSInlineHost213910::~BSInlineHost213910() {
    if (reference) reference->DecRefCount();
}
