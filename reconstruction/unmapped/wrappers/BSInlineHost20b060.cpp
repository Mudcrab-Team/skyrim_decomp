// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost20b060, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x20b060 BSInlineHost20b060::~BSInlineHost20b060
#include "BSInlineHost20b060.h"
BSInlineHost20b060::~BSInlineHost20b060() {
    if (reference) reference->DecRefCount();
}
