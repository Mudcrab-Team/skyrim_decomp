// Source exposure: mixed (pinned image and published community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original explicit instantiation of std::_Func_impl_no_alloc over stand-in callables.
// std::_Func_impl_no_alloc slots and callable sizes: OBSERVED
// StdCallableCopyMoveLeaves, CallableTable*, CallableObject*: GUESS(low) STANDIN; callable contents and signatures unknown.
// Adapted bodies: none
#pragma once
#include <functional>

// capturedWord: GUESS(low) STANDIN; the copied word is typed, its original meaning is unknown.
struct CallableTable18eef70
{
    unsigned long long capturedWord;
    void operator()() const {}
};
static_assert(sizeof(CallableTable18eef70) == 8, "observed callable word size");

struct StdCallableCopyMoveLeaves
{
};
