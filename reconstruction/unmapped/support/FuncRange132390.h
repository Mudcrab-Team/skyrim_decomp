// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Func132390, FuncRange132390: GUESS(low) STANDIN
#pragma once

#include <functional>

using Func132390 = std::function<void()>;

struct FuncRange132390
{
    ~FuncRange132390();  // compared: 0x132390

    Func132390* first;  // 0x00
    Func132390* last;   // 0x08
};
