// Source exposure: mixed (represented community declarations and local binary analysis).
// MenuEventHandlerStorageLayout, DirectionHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/D/DirectionHandler.h; GPL-3.0.
// 0x960b80 DeletingLeaf960b80::~DeletingLeaf960b80
void operator delete(void*, unsigned __int64) noexcept;
#include "DirectionHandlerStorageLayout.h"
namespace ResearchLayouts {
inline MenuEventHandlerStorageLayout::~MenuEventHandlerStorageLayout() {}
inline DirectionHandlerStorageLayout::~DirectionHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::DirectionHandlerStorageLayout) == 48, "independently observed allocation size");
static ResearchLayouts::DirectionHandlerStorageLayout object;
