// Source exposure: binary-analysis (local access, copy, RTTI and size evidence).
// FunctionPointerCallableLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// _Func_impl_no_alloc: EXE_RTTI
// Code origin: original declarations from target-derived physical facts; no external body or declaration reused.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// FunctionPointerCallableLayoutValue: GUESS(low) STANDIN; scalar copy-slot aggregate, not a recovered callable type.
// callable, value08, value10, value11, value12, value18: GUESS(low) STANDIN; independently copied slots.
// Function: GUESS(low) STANDIN; RTTI establishes a function-pointer category, signature is not reconstructed.
using Function = void (*)();
struct FunctionPointerCallableLayoutValue {
    Function value08;
};
class FunctionPointerCallableLayout { public: virtual ~FunctionPointerCallableLayout(); FunctionPointerCallableLayoutValue callable; };
static_assert(sizeof(FunctionPointerCallableLayout) == 16, "independent slot-four sized delete");
static_assert(offsetof(FunctionPointerCallableLayout,callable)==8,"target callable address");
static_assert(offsetof(FunctionPointerCallableLayoutValue,value08) == 0, "independent scalar copy offset");
}
