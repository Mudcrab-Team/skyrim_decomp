// Source exposure: mixed (represented community declarations and local binary analysis).
// IGiftMenuScriptCallbackStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/I/IGiftMenuScriptCallback.h; GPL-3.0.
// 0xa0d410 DeletingLeafa0d410::~DeletingLeafa0d410
void operator delete(void*, unsigned __int64) noexcept;
#include "IGiftMenuScriptCallbackStorageLayout.h"
namespace ResearchLayouts {
inline IGiftMenuScriptCallbackStorageLayout::~IGiftMenuScriptCallbackStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::IGiftMenuScriptCallbackStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::IGiftMenuScriptCallbackStorageLayout object;
