// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BShkbAnimationGraph: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BShkbAnimationGraph::ReleaseScratchBuffers: GUESS(low); honest stand-in replacing the PDB-listed name SetGraphVariableInt because this zero-parameter function releases four thread-local scratch buffers
// 0xb34e40 BShkbAnimationGraph::ReleaseScratchBuffers
#include "BShkbAnimationGraph_b34e40.h"

namespace
{
    constexpr std::uint32_t kBufferSize = 0xC00;

    void FreeGraphBuffer(void* a_buffer)
    {
        auto* block = static_cast<TlsMemoryBlock*>(TlsGetValue(g_tlsMemoryIndex));
        block->allocator->Free(a_buffer, kBufferSize);
    }
}

// Release the four thread-local graph scratch buffers if allocated and clear their pointers.
void BShkbAnimationGraph::ReleaseScratchBuffers()
{
    if (buffer0) {
        FreeGraphBuffer(buffer0);
        FreeGraphBuffer(buffer1);
        FreeGraphBuffer(buffer2);
        FreeGraphBuffer(buffer3);
        buffer0 = nullptr;
        buffer1 = nullptr;
        buffer2 = nullptr;
        buffer3 = nullptr;
    }
}
