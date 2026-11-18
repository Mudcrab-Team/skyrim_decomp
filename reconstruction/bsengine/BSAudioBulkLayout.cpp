// Source exposure: mixed (represented community declarations and local binary analysis).
// BSAudioBulkLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v5
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/B/BSAudio.h; GPL-3.0.
// 0xcd62b0 DeletingLeafcd62b0::~DeletingLeafcd62b0
void operator delete(void*, unsigned __int64) noexcept;
#include "BSAudioBulkLayout.h"
namespace ResearchLayouts {
inline BSAudioBulkLayout::~BSAudioBulkLayout() {}
}
static_assert(sizeof(ResearchLayouts::BSAudioBulkLayout) == 24, "independently observed allocation size");
static ResearchLayouts::BSAudioBulkLayout object;
