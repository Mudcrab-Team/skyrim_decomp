// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x158ad50 BSImagespaceShaderISBlur::Function158ad50
#include "BSImagespaceShaderISBlur_158ad50.h"
#include <cstring>

void BSImagespaceShaderISBlur::Function158ad50(const void* a_src)
{
    if (unk1A1 != 0) {
        return;
    }

    Function1579120(0, 0, 0);
    void* buffer;
    void** handle = g_constantPool.Function10104f0(0x4C, &buffer, 2);
    memcpy_s(buffer, 0x130, a_src, 0x130);
    if (*handle) {
        g_renderer->VFunc15(*handle, 0);
    }
    g_renderer->VFunc07(2, 1, handle);
    g_renderer->VFunc16(2, 1, handle);
}
