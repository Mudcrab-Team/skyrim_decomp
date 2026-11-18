// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// NiIntersectorFieldLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v13
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
// 0xf43980 DeletingLeaff43980::~DeletingLeaff43980
void operator delete(void*, unsigned __int64) noexcept;
#include "NiIntersectorFieldLayout.h"
namespace ResearchLayouts {
inline NiIntersectorFieldLayout::~NiIntersectorFieldLayout() {}
}
static_assert(sizeof(ResearchLayouts::NiIntersectorFieldLayout) == 64, "independently observed allocation size");
static ResearchLayouts::NiIntersectorFieldLayout object;
