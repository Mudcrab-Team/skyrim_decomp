// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// BoundPairCallableLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// _Func_impl_no_alloc: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// BoundPairCallableLayoutValue: GUESS(low) STANDIN; scalar copy-slot aggregate, not a recovered callable type.
// callable, value08, value10, value11, value12, value18: GUESS(low) STANDIN; independently copied slots.
struct BoundPairCallableLayoutValue {
    std::uint64_t value08;
    std::uint64_t value10;
};
class BoundPairCallableLayout { public: virtual ~BoundPairCallableLayout(); BoundPairCallableLayoutValue callable; };
static_assert(sizeof(BoundPairCallableLayout) == 24, "independent slot-four sized delete");
static_assert(offsetof(BoundPairCallableLayout,callable)==8,"target callable address");
static_assert(offsetof(BoundPairCallableLayoutValue,value08) == 0, "independent scalar copy offset");
static_assert(offsetof(BoundPairCallableLayoutValue,value10) == 8, "independent scalar copy offset");
}
