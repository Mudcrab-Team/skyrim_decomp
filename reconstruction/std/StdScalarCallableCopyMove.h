// Source exposure: mixed (pinned image and published community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original explicit instantiation of std::_Func_impl_no_alloc over stand-in callables.
// std::_Func_impl_no_alloc slots and callable sizes: OBSERVED
// StdScalarCallableCopyMove, CallableTable*, CallableObject*: GUESS(low) STANDIN; callable contents and signatures unknown.
// Adapted bodies: none
#pragma once
#include <functional>

struct SplitCallableState
{
    void* first;
    unsigned long long second;

    SplitCallableState() = default;
    SplitCallableState(const SplitCallableState& other) noexcept : first(other.first), second(other.second) {}
    SplitCallableState(SplitCallableState&& other) noexcept : first(other.first), second(other.second) {}
    void operator()() const {}
};

struct StdScalarCallableCopyMove
{
};
