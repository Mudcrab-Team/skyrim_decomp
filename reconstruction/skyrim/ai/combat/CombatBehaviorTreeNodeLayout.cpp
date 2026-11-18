// Recipe: reconstruction/recipes/represented-wrapper-o2.json
// Source exposure: mixed (represented community declarations and local binary analysis).
// object: GUESS(low)
// Code origin: original wrapper emission harness; represented declarations are included.
// Origin: represented-deleting-wrapper v3
// 0x55ee10 CombatBehaviorTreeNodeLayout::~CombatBehaviorTreeNodeLayout
void operator delete(void*, unsigned __int64) noexcept;
#include "CombatBehaviorTreeNodeLayout.h"
static_assert(sizeof(ResearchLayouts::CombatBehaviorTreeNodeLayout) == 40, "represented allocation size");
static ResearchLayouts::CombatBehaviorTreeNodeLayout object;
