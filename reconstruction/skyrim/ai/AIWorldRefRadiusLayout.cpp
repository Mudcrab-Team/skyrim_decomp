// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// AIWorldLocationLayout, AIWorldRefRadiusLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v13
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
// 0x449750 DeletingLeaf449750::~DeletingLeaf449750
void operator delete(void*, unsigned __int64) noexcept;
#include "AIWorldRefRadiusLayout.h"
namespace ResearchLayouts {
inline AIWorldLocationLayout::~AIWorldLocationLayout() {}
inline AIWorldRefRadiusLayout::~AIWorldRefRadiusLayout() {}
}
static_assert(sizeof(ResearchLayouts::AIWorldRefRadiusLayout) == 32, "independently observed allocation size");
static ResearchLayouts::AIWorldRefRadiusLayout object;
