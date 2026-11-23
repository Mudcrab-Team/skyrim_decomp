// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1a4c80 TES::GetModeName
// Adapted bodies: none
#include "TES_1a4c80.h"

const char* TES::GetModeName(std::uint32_t mode)
{
    switch (mode) {
    case 0:
        return "Off";
    case 1:
        return "On";
    case 2:
        return "Over Everything";
    default:
        return "Unrecognized mode";
    }
}
