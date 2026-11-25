// Source exposure: mixed (pinned community declarations and private target analysis).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: CC0-1.0
// 0x1a4c80 TES::Function1a4c80
// Adapted bodies: none
#include "TES_1a4c80.h"

// Selects one of three indexed addresses, or the default address.
const void* TES::Function1a4c80(std::int32_t selector)
{
    switch (selector) {
    case 0:
        return g_tesSelectorZero;
    case 1:
        return g_tesSelectorOne;
    case 2:
        return g_tesSelectorTwo;
    default:
        return g_tesSelectorDefault;
    }
}
