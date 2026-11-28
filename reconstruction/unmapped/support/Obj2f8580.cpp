// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2f8580 Obj2f8580::operator delete
// CI hash: 0x2f8580 ??3Obj2f8580@@SAXPEAX_K@Z
// Adapted bodies: none
#include "Obj2f8580.h"

// Guess: free an object through the thread-local allocator using its stored size when present.
void Obj2f8580::operator delete(void* a_ptr, std::size_t a_size)
{
    const std::uint16_t storedSize = static_cast<Obj2f8580*>(a_ptr)->m_memSize;
    ThreadCtx2f8580* ctx = static_cast<ThreadCtx2f8580*>(TlsGetValue(gTlsIndex2f8580));
    const std::int32_t bytes = (storedSize == 0xFFFFu) ? static_cast<std::int32_t>(a_size) : static_cast<std::int32_t>(storedSize);
    ctx->m_alloc->Free(a_ptr, bytes);
}
