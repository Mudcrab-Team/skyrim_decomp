// Source exposure: mixed (binary-analysis, community-headers).
// Original reconstruction; community-derived shared types are included with their notice.
// BSInlineHost20b030, Invoke, reference, p145_lookup_a, p145_lookup_b, p145_consume_a, p145_consume_b, p145_get_handle: GUESS(low) STANDIN
// 0x20b030 BSInlineHost20b030::~BSInlineHost20b030
#include "BSInlineHost20b030.h"
BSInlineHost20b030::~BSInlineHost20b030() {
    if (reference) reference->DecRefCount();
}
