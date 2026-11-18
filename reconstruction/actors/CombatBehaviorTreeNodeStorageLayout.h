// Source exposure: mixed (community declarations and pinned image analysis).
// Declarations derived from powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944; GPL-3.0.
// CombatBehaviorTreeNodeObjectBase, CombatBehaviorTreeNodeObject: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// CombatBehaviorTreeNodeLayout, NodeName: GUESS(low) STANDIN
// Adapted from published p106 represented declaration reconstruction/actors/CombatBehaviorTreeNodeLayout.h.
// NodeNameStorageLayout, CombatBehaviorTreeNodeStorageLayout, CombatBehaviorTreeNodeObjectBaseStorageLayout, CombatBehaviorTreeNodeObjectStorageLayout: GUESS(medium) STANDIN; compilation-local represented type aliases.
#pragma once
#include <cstdint>
#include <cstddef>

namespace ResearchLayouts {
struct NodeNameStorageLayout { const char* entry; };
class CombatBehaviorTreeNodeStorageLayout {
public:
    virtual ~CombatBehaviorTreeNodeStorageLayout();
    NodeNameStorageLayout name;
    CombatBehaviorTreeNodeStorageLayout* parent;
    CombatBehaviorTreeNodeStorageLayout** children;
    std::uint32_t childCount;
};
template<class Behavior>
class CombatBehaviorTreeNodeObjectBaseStorageLayout : public CombatBehaviorTreeNodeStorageLayout {
public:
    ~CombatBehaviorTreeNodeObjectBaseStorageLayout() override;
};
template<class Behavior>
class CombatBehaviorTreeNodeObjectStorageLayout : public CombatBehaviorTreeNodeObjectBaseStorageLayout<Behavior> {
public:
    ~CombatBehaviorTreeNodeObjectStorageLayout() override;
};
static_assert(sizeof(CombatBehaviorTreeNodeStorageLayout) == 0x28, "behavior tree node layout");
static_assert(offsetof(CombatBehaviorTreeNodeStorageLayout, name) == 8, "name offset");
static_assert(offsetof(CombatBehaviorTreeNodeStorageLayout, parent) == 0x10, "parent offset");
static_assert(offsetof(CombatBehaviorTreeNodeStorageLayout, children) == 0x18, "children offset");
static_assert(offsetof(CombatBehaviorTreeNodeStorageLayout, childCount) == 0x20, "child count offset");
static_assert(sizeof(CombatBehaviorTreeNodeObjectStorageLayout<void>) == 0x28, "fieldless specialization");
}
