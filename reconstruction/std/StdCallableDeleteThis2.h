// Source exposure: mixed (pinned image and published community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original explicit instantiation of std::_Func_impl_no_alloc over stand-in callables.
// std::_Func_impl_no_alloc slots and callable sizes: OBSERVED
// StdCallableDeleteThis2, CallableTable*, CallableObject*: GUESS(low) STANDIN; callable contents and signatures unknown.
// Adapted bodies: none
#pragma once
#include <functional>

// Stand-in callable: Bytes of stored state and a call operator that is never reached.
template <unsigned long long Bytes>
struct StdCallableState
{
    alignas(8) unsigned char state[Bytes];
    void operator()() const {}
};

struct StdCallableDeleteThis2
{
};
