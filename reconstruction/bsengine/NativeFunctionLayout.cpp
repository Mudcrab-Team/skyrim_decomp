// Recipe: reconstruction/recipes/represented-wrapper-o2.json
// Source exposure: mixed (represented community declarations and local binary analysis).
// object: GUESS(low)
// Code origin: original wrapper emission harness; represented declarations are included.
// Origin: represented-deleting-wrapper v3
// 0x9fdcd0 NativeFunctionLayout::~NativeFunctionLayout
void operator delete(void*, unsigned __int64) noexcept;
#include "NativeFunctionLayout.h"
static_assert(sizeof(ResearchLayouts::NativeFunctionLayout) == 88, "represented allocation size");
static ResearchLayouts::NativeFunctionLayout object;
