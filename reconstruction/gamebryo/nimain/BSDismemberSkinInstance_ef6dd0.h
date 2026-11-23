// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSDismemberSkinInstance, BSDismemberSkinInstance::Functionef6dd0, BSDismemberSkinInstance::forwardTarget, BinaryStreamLike, BinaryStreamLike::position, BinaryStreamLike::io, BinaryStreamLike::IoFunction: GUESS(low)
#pragma once

#include <cstdint>

// Stand-in for the stream the receiver forwards to: a running position at 0x08 and a byte-I/O callback at 0x18.
class BinaryStreamLike
{
public:
    typedef std::uint32_t (*IoFunction)(BinaryStreamLike* self, void* buffer, std::uint32_t totalBytes, std::uint32_t* componentSizes, std::uint32_t numComponents);

    std::uint8_t pad00[0x08];  // 0x00
    std::uint32_t position;  // 0x08
    std::uint8_t pad0c[0x0c];  // 0x0c
    IoFunction io;  // 0x18
};

// The class keeps the placeholder name of the unit.
class BSDismemberSkinInstance
{
public:
    void Functionef6dd0(void* buffer, std::uint32_t count);

    std::uint8_t pad00[0x2a0];  // 0x00
    BinaryStreamLike* forwardTarget;  // 0x2a0
};
