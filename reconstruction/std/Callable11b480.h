// Source exposure: binary-analysis (the pinned image listing).
// Template from the compiler's standard headers; the source is our own instantiation.
// Code origin: original; explicit instantiation of std::_Func_impl_no_alloc over a stand-in callable
// SPDX-License-Identifier: CC0-1.0
// Callable11b480: GUESS(low) STANDIN
#pragma once

#include <cstdint>
#include <functional>

struct Callable11b480
{
    void* first;
    bool flag0;
    bool flag1;
    bool flag2;
    std::uint64_t second;

    Callable11b480() = default;
    Callable11b480(const Callable11b480& a_other) noexcept
        : first(a_other.first), flag0(a_other.flag0), flag1(a_other.flag1), flag2(a_other.flag2), second(a_other.second)
    {}
    void operator()() const {}
};
