// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// AIWorldLocationLayout, AIWorldPointRadiusLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v13
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
// 0x449720 DeletingLeaf449720::~DeletingLeaf449720
void operator delete(void*, unsigned __int64) noexcept;
#include "AIWorldPointRadiusLayout.h"
namespace ResearchLayouts {
inline AIWorldLocationLayout::~AIWorldLocationLayout() {}
inline AIWorldPointRadiusLayout::~AIWorldPointRadiusLayout() {}
}
static_assert(sizeof(ResearchLayouts::AIWorldPointRadiusLayout) == 56, "independently observed allocation size");
static ResearchLayouts::AIWorldPointRadiusLayout object;
