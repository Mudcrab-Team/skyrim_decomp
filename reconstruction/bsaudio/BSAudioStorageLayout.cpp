// Source exposure: mixed (represented community declarations and local binary analysis).
// BSAudioStorageLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSAudio.h; GPL-3.0.
// 0xcd4be0 DeletingLeafcd4be0::~DeletingLeafcd4be0
void operator delete(void*, unsigned __int64) noexcept;
#include "BSAudioStorageLayout.h"
namespace ResearchLayouts {
inline BSAudioStorageLayout::~BSAudioStorageLayout() {}
}
static_assert(sizeof(ResearchLayouts::BSAudioStorageLayout) == 24, "independently observed allocation size");
static ResearchLayouts::BSAudioStorageLayout object;
