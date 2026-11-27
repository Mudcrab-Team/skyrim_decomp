// CI hash: 0x1020aa0 ?Function1020aa0@Unk1020aa0@@SAPEAXXZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1020aa0: STANDIN GUESS(low)
// Unk1020aa0::Function1020aa0: GUESS(low)
// gComInstance, gInterfaceID: GUESS(low)
// 0x1020aa0 Unk1020aa0::Function1020aa0
#include "Unk1020aa0_1020aa0.h"

// Create the shared COM instance on demand and clear it on failure.
void* Unk1020aa0::Function1020aa0()
{
    if (!gComInstance && FAILED(CoCreateInstance(gClassID, nullptr, CLSCTX_INPROC_SERVER, gInterfaceID, &gComInstance))) {
        gComInstance = nullptr;
        return nullptr;
    }
    return gComInstance;
}
