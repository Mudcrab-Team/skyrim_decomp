// Source exposure: mixed (represented community declarations and local binary analysis).
// IMessageBoxCallbackStorageLayout, NeedToUpdateCreationClubCallbackStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/N/NeedToUpdateCreationClubCallback.h; GPL-3.0.
// 0x95e670 DeletingLeaf95e670::~DeletingLeaf95e670
void operator delete(void*, unsigned __int64) noexcept;
#include "NeedToUpdateCreationClubCallbackStorageLayout.h"
namespace ResearchLayouts {
inline IMessageBoxCallbackStorageLayout::~IMessageBoxCallbackStorageLayout() {}
inline NeedToUpdateCreationClubCallbackStorageLayout::~NeedToUpdateCreationClubCallbackStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::NeedToUpdateCreationClubCallbackStorageLayout) == 16, "independently observed allocation size");
static ResearchLayouts::NeedToUpdateCreationClubCallbackStorageLayout object;
