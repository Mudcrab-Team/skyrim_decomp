// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// AIWorldLocationLayout, AIWorldInteriorCellLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Origin: scalar-deleting-leaf v13
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
// 0x4496f0 DeletingLeaf4496f0::~DeletingLeaf4496f0
void operator delete(void*, unsigned __int64) noexcept;
#include "AIWorldInteriorCellLayout.h"
namespace ResearchLayouts {
inline AIWorldLocationLayout::~AIWorldLocationLayout() {}
inline AIWorldInteriorCellLayout::~AIWorldInteriorCellLayout() {}
}
static_assert(sizeof(ResearchLayouts::AIWorldInteriorCellLayout) == 32, "independently observed allocation size");
static ResearchLayouts::AIWorldInteriorCellLayout object;
