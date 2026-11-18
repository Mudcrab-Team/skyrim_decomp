// Source exposure: mixed (represented community declarations and local binary analysis).
// MenuEventHandlerStorageLayout, QuickSaveLoadHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/Q/QuickSaveLoadHandler.h; GPL-3.0.
// 0x960c50 DeletingLeaf960c50::~DeletingLeaf960c50
void operator delete(void*, unsigned __int64) noexcept;
#include "QuickSaveLoadHandlerStorageLayout.h"
namespace ResearchLayouts {
inline MenuEventHandlerStorageLayout::~MenuEventHandlerStorageLayout() {}
inline QuickSaveLoadHandlerStorageLayout::~QuickSaveLoadHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::QuickSaveLoadHandlerStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::QuickSaveLoadHandlerStorageLayout object;
