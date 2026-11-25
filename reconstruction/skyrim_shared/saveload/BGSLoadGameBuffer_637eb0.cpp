// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction; community names and declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x637eb0 BGSLoadGameBuffer::ReadBlock16
// Adapted bodies: none. Target sse-steam-1-7-104; identity is RVA, names remain evidence labels.
#include "BGSLoadGameBuffer_637eb0.h"
#include <intrin.h>

// Block16, ConsumeBlock16: GUESS(low); opaque block and observed helper boundary.
struct Block16 { float words[4]; };
extern void ConsumeBlock16(const Block16* block, void* output);

void BGSLoadGameBuffer::ReadBlock16(void* output)
{
    Block16 block;
    const std::uint32_t position = bufferPosition;
    // Unaligned SIMD load preserves the opaque sixteen-byte block as one value.
    const __m128 value = _mm_loadu_ps(reinterpret_cast<const float*>(buffer + position));
    bufferPosition = position + sizeof(block);
    // The block has ordinary float alignment; store it without assuming SIMD alignment.
    _mm_storeu_ps(block.words, value);
    ConsumeBlock16(&block, output);
}
