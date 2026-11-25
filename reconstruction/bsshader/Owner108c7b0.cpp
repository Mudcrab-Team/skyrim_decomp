// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: original bodies written from the local listing; declarations from CommonLibSSE-NG. Stamped as a twin of matched 0x152aa40 (bsshader/BSEffectShaderProperty): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x108c7b0 Owner108c7b0::Function108c7b0
#include "Owner108c7b0.h"

// guess: same compiled code as matched 0x152aa40 apart from relocated fields; its role here is not established.
void Owner108c7b0::Function108c7b0(const void* buffer)
{
    std::uint32_t size = 16;
    NiBinaryStream* stream = writeStream;
    stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, 16, &size, 1);
}
