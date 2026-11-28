// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x132390 FuncRange132390::~FuncRange132390
// Adapted bodies: none
#include "FuncRange132390.h"

// Destroys all std::function objects in the [first, last) range.
FuncRange132390::~FuncRange132390()
{
    auto* const end = last;
    for (auto* it = first; it != end; ++it)
    {
        it->~Func132390();
    }
}
