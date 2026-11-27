// Source exposure: mixed.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Renderer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Renderer::Function1009cf0: GUESS(low)
// Renderer::lock: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <Windows.h>



class Renderer
{
public:
    void Function1009cf0();
    std::uint8_t unknown0[10224];
    CRITICAL_SECTION lock;
};
static_assert(offsetof(Renderer, lock) == 10224, "field offset");
