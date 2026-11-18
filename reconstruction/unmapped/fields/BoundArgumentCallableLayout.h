// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// BoundArgumentCallableLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// _Func_impl_no_alloc: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// BoundArgumentCallableLayoutValue: GUESS(low) STANDIN; scalar copy-slot aggregate, not a recovered callable type.
// callable, value08, value10, value11, value12, value18: GUESS(low) STANDIN; independently copied slots.
struct BoundArgumentCallableLayoutValue {
    std::uint64_t value08;
    std::uint8_t value10;
    std::uint8_t value11;
    std::uint8_t value12;
    std::uint64_t value18;
};
class BoundArgumentCallableLayout { public: virtual ~BoundArgumentCallableLayout(); BoundArgumentCallableLayoutValue callable; };
static_assert(sizeof(BoundArgumentCallableLayout) == 32, "independent slot-four sized delete");
static_assert(offsetof(BoundArgumentCallableLayout,callable)==8,"target callable address");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value08) == 0, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value10) == 8, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value11) == 9, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value12) == 10, "independent scalar copy offset");
static_assert(offsetof(BoundArgumentCallableLayoutValue,value18) == 16, "independent scalar copy offset");
}
