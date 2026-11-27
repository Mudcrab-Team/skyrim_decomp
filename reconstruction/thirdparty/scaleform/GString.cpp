// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original implementations based on the pinned game build, with the cited declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcfc9d0 GString::GString
// 0xcfe210 GString::BernsteinHashFunction
// 0xcfe240 GString::BernsteinHashFunctionCIS
// Adapted bodies: none
#include "GString.h"

GString::GString()
{
    // A default string shares the empty descriptor.
    pData = &NullData;
    NullData.AddRef();
}

std::size_t GString::BernsteinHashFunction(const void* dataIn, std::size_t size, std::size_t seed)
{
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(dataIn);
    std::size_t hash = seed;
    while (size > 0) {
        size--;
        hash = (hash * 33) ^ bytes[size];
    }
    return hash;
}

std::size_t GString::BernsteinHashFunctionCIS(const void* dataIn, std::size_t size, std::size_t seed)
{
    // Case-insensitive variant: ASCII capitals hash as their lower-case letters.
    const std::uint8_t* bytes = static_cast<const std::uint8_t*>(dataIn);
    std::size_t hash = seed;
    while (size > 0) {
        size--;
        unsigned int c = bytes[size];
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
        }
        hash = (hash * 33) ^ c;
    }
    return hash;
}
