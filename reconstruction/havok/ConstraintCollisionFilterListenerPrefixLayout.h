// Source exposure: mixed (included pinned community/FNV interface declarations and independent target RTTI/construction/storage analysis).
// Code origin: original physical storage declarations and defaulted prefix construction; no external implementation body reused.
// hkpPairCollisionFilter, hkpConstraintCollisionFilter: EXE_RTTI
// PairFilterEntriesLayout, PairFilterTableStorageLayout, PairCollisionFilterStorageLayout, ConstraintCollisionFilterListenerPrefixLayout, ConstraintCollisionFilterListenerStorageLayout, entries, elementCount, indexMask, disabledPairs, childFilter: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include <cstdint>
#include "CollisionFilterLayout.h"
namespace ResearchLayouts {
class PairFilterEntriesLayout;
struct PairFilterTableStorageLayout {
    PairFilterEntriesLayout* entries;
    std::uint32_t elementCount;
    std::int32_t indexMask;
};
class PairCollisionFilterStorageLayout : public CollisionFilterLayout {
public:
    ~PairCollisionFilterStorageLayout() override;
    PairFilterTableStorageLayout disabledPairs;
    ReferencedObjectLayout* childFilter;
};
class ConstraintCollisionFilterListenerPrefixLayout : public PairCollisionFilterStorageLayout, public ConstraintListenerLayout {
public:
    ConstraintCollisionFilterListenerPrefixLayout();
    ~ConstraintCollisionFilterListenerPrefixLayout() override;
};
struct ConstraintCollisionFilterListenerStorageLayout {
    CollisionFilterStorageLayout collision;
    PairFilterTableStorageLayout disabledPairs;
    ReferencedObjectLayout* childFilter;
    const void* const* listener;
};
static_assert(sizeof(PairFilterTableStorageLayout) == 16, "observed pointer/two-word field group");
static_assert(offsetof(PairFilterTableStorageLayout, entries) == 0, "observed pointer slot");
static_assert(offsetof(PairFilterTableStorageLayout, elementCount) == 8, "observed first word");
static_assert(offsetof(PairFilterTableStorageLayout, indexMask) == 12, "observed second word");
static_assert(sizeof(PairCollisionFilterStorageLayout) == 96, "public collision storage plus observed fields");
static_assert(offsetof(PairCollisionFilterStorageLayout, disabledPairs) == 72, "observed cleanup field group");
static_assert(offsetof(PairCollisionFilterStorageLayout, childFilter) == 88, "observed child pointer");
static_assert(sizeof(ConstraintCollisionFilterListenerPrefixLayout) == 104, "represented primary/listener prefix");
static_assert(sizeof(ConstraintCollisionFilterListenerStorageLayout) == 104, "physical prefix mirror");
static_assert(offsetof(ConstraintCollisionFilterListenerStorageLayout, disabledPairs) == 72, "observed group offset");
static_assert(offsetof(ConstraintCollisionFilterListenerStorageLayout, childFilter) == 88, "observed child offset");
static_assert(offsetof(ConstraintCollisionFilterListenerStorageLayout, listener) == 96, "independent target RTTI listener offset");
}
