// Source exposure: mixed (represented community declarations and local binary analysis).
// MenuEventHandlerStorageLayout, ClickHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/C/ClickHandler.h; GPL-3.0.
// 0x960b20 DeletingLeaf960b20::~DeletingLeaf960b20
void operator delete(void*, unsigned __int64) noexcept;
#include "ClickHandlerStorageLayout.h"
namespace ResearchLayouts {
inline MenuEventHandlerStorageLayout::~MenuEventHandlerStorageLayout() {}
inline ClickHandlerStorageLayout::~ClickHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ClickHandlerStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ClickHandlerStorageLayout object;
