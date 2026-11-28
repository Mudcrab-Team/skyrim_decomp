// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Func132180, FuncAllocator132180: GUESS(low) STANDIN
#pragma once

#include <functional>

using Func132180 = std::function<void()>;

struct FuncAllocator132180
{
    void Destroy(Func132180* a_ptr);  // compared: 0x132180
};
