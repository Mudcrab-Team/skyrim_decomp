// Source exposure: mixed (represented community declarations and local binary analysis).
// MenuEventHandlerStorageLayout, ConsoleOpenHandlerStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/C/ConsoleOpenHandler.h; GPL-3.0.
// 0x960b50 DeletingLeaf960b50::~DeletingLeaf960b50
void operator delete(void*, unsigned __int64) noexcept;
#include "ConsoleOpenHandlerStorageLayout.h"
namespace ResearchLayouts {
inline MenuEventHandlerStorageLayout::~MenuEventHandlerStorageLayout() {}
inline ConsoleOpenHandlerStorageLayout::~ConsoleOpenHandlerStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::ConsoleOpenHandlerStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::ConsoleOpenHandlerStorageLayout object;
