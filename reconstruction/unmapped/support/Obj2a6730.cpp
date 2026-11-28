// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2a6730 Obj2a6730::Function2a6730
// Adapted bodies: none
#include "Obj2a6730.h"

// Sets default floating-point image-space parameters.
void Obj2a6730::Function2a6730()
{
    f20 = 3.0f;
    f24 = 7.0f;
    f28 = 0.6f;
    f2C = 0.5f;
    f30 = 0.15f;
    f34 = 0.15f;
    f3C = 1.5f;
    f38 = 1.8f;
    f40 = 3.0f;
    f44 = 0.9f;
    f48 = 1.5f;
    f4C = 1.1f;
    for (int i = 0; i < 7; ++i) {
        tail[i] = 0.0f;
    }
}
