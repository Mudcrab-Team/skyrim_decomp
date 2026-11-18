// Source exposure: mixed (represented community declarations and local binary analysis).
// IUIMessageDataStorageLayout, ModManagerDataStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/M/ModManagerData.h; GPL-3.0.
// 0x9a8100 DeletingLeaf9a8100::~DeletingLeaf9a8100
void operator delete(void*, unsigned __int64) noexcept;
#include "ModManagerDataStorageLayout.h"
namespace ResearchLayouts {
inline IUIMessageDataStorageLayout::~IUIMessageDataStorageLayout() {}
inline ModManagerDataStorageLayout::~ModManagerDataStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ModManagerDataStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::ModManagerDataStorageLayout object;
