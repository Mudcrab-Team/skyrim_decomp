// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiStream, NiStream::Functionee45a0, NiStream::state, NiStream::worker, NiStreamWorker, NiStreamWorker::Forward: GUESS(low)
#pragma once

#include <cstdint>

// Stand-in for the object at the worker slot; the callee is declared without a body.
class NiStreamWorker
{
public:
    void Forward();
};

class NiStream
{
public:
    void Functionee45a0();

    std::uint8_t pad00[0x2d8];  // 0x00
    std::uint32_t state;  // 0x2d8
    std::uint8_t pad2dc[0x14];  // 0x2dc
    NiStreamWorker* worker;  // 0x2f0
};
