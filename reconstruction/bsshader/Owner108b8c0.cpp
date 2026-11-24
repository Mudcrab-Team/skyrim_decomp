// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: original bodies written from the local listing; declarations from CommonLibSSE-NG. Stamped as a twin of matched 0x152aa00 (bsshader/BSEffectShaderProperty): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x108b8c0 Owner108b8c0::Function108b8c0
#include "Owner108b8c0.h"

// guess: same compiled code as matched 0x152aa00 apart from relocated fields; its role here is not established.
void Owner108b8c0::Function108b8c0(void* buffer)
{
    std::uint32_t size = 16;
    NiBinaryStream* stream = readStream;
    stream->_absoluteCurrentPos += stream->_readFn(stream, buffer, 16, &size, 1);
}
