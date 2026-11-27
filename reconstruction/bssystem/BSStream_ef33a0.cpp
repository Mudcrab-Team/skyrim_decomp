// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSStream::Functionef33a0: GUESS(low)
// 0xef33a0 BSStream::Functionef33a0
#include "BSStream_ef33a0.h"

// Read a block of 16-byte elements (four 4-byte components each) from the binary input stream.
void BSStream::Functionef33a0(void* a_dest, std::uint32_t a_count)
{
    NiBinaryStream* stream = iStr;
    std::uint32_t componentSize = 4u;
    stream->absoluteCurrentPos += stream->readFn(stream, a_dest, a_count * 16u, &componentSize, 1);
}
