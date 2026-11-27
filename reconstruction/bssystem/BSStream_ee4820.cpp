// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSStream::Functionee4820: GUESS(low)
// 0xee4820 BSStream::Functionee4820
#include "BSStream_ee4820.h"

// Read a length-prefixed string from the stream into a newly allocated buffer.
void BSStream::Functionee4820(char*& a_out)
{
    std::int32_t length;
    iStr->ReadInt(&length);
    if (length > 0) {
        a_out = NiAlloc(static_cast<std::size_t>(length + 1));
        iStr->ReadBytes(a_out, static_cast<std::uint32_t>(length));
        a_out[length] = 0;
    } else {
        a_out = nullptr;
    }
}
