// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x28e3b0 Obj28e3b0::Function28e3b0
// Adapted bodies: none
#include "Obj28e3b0.h"

// Frees payload under memory allocation context 0x65 and nulls the pointer.
void Obj28e3b0::Function28e3b0()
{
    std::uint32_t saved = g_allocContext_tls_0x768;
    g_allocContext_tls_0x768 = 0x65u;
    delete payload;
    payload = nullptr;
    g_allocContext_tls_0x768 = saved;
}
