// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Unit1fb4a0::ClearBuffers1fb4a0, treated as adapted: shaped like BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Buffer1fb4a0, Unit1fb4a0, ClearBuffers1fb4a0, Deallocate, data, unk08, count, unk14, buffers: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Buffer1fb4a0
{
    void* data;          // 00
    std::uint64_t unk08; // 08
    std::uint32_t count; // 10
    std::uint32_t unk14; // 14

    void Deallocate();
};
static_assert(sizeof(Buffer1fb4a0) == 0x18, "Buffer1fb4a0 size");
static_assert(offsetof(Buffer1fb4a0, count) == 0x10, "Buffer1fb4a0::count offset");

struct Unit1fb4a0
{
    Buffer1fb4a0 buffers[3];  // 00

    void ClearBuffers1fb4a0();  // compared: 0x1fb4a0
};
