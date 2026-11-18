// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// TESRegionObjectBaseLayout, TESRegionGrassObjectLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v13
// Code origin: original minimal declarations from independently checked target field accesses and RTTI.
// 0x254510 DeletingLeaf254510::~DeletingLeaf254510
void operator delete(void*, unsigned __int64) noexcept;
#include "TESRegionGrassObjectLayout.h"
namespace ResearchLayouts {
inline TESRegionObjectBaseLayout::~TESRegionObjectBaseLayout() {}
inline TESRegionGrassObjectLayout::~TESRegionGrassObjectLayout() {}
}
static_assert(sizeof(ResearchLayouts::TESRegionGrassObjectLayout) == 24, "independently observed allocation size");
static ResearchLayouts::TESRegionGrassObjectLayout object;
