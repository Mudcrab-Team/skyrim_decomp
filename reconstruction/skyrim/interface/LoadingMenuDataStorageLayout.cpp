// Source exposure: mixed (represented community declarations and local binary analysis).
// IUIMessageDataStorageLayout, LoadingMenuDataStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/L/LoadingMenuData.h; GPL-3.0.
// 0x98d930 DeletingLeaf98d930::~DeletingLeaf98d930
void operator delete(void*, unsigned __int64) noexcept;
#include "LoadingMenuDataStorageLayout.h"
namespace ResearchLayouts {
inline IUIMessageDataStorageLayout::~IUIMessageDataStorageLayout() {}
inline LoadingMenuDataStorageLayout::~LoadingMenuDataStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::LoadingMenuDataStorageLayout) == 32, "independently observed allocation size");
static ResearchLayouts::LoadingMenuDataStorageLayout object;
