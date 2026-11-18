// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// ScalarCaptureCallableLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// _Func_impl_no_alloc: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// ScalarCaptureCallableLayoutValue: GUESS(low) STANDIN; scalar copy-slot aggregate, not a recovered callable type.
// callable, value08, value10, value11, value12, value18: GUESS(low) STANDIN; independently copied slots.
struct ScalarCaptureCallableLayoutValue {
    std::uint64_t value08;
};
class ScalarCaptureCallableLayout { public: virtual ~ScalarCaptureCallableLayout(); ScalarCaptureCallableLayoutValue callable; };
static_assert(sizeof(ScalarCaptureCallableLayout) == 16, "independent slot-four sized delete");
static_assert(offsetof(ScalarCaptureCallableLayout,callable)==8,"target callable address");
static_assert(offsetof(ScalarCaptureCallableLayoutValue,value08) == 0, "independent scalar copy offset");
}
