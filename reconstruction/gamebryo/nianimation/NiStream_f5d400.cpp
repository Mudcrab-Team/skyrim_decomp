// Source exposure: mixed (pinned community declarations; private target observations).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf5d400 NiStream::Functionf5d400
// Adapted bodies: none.
#include "NiStream_f5d400.h"

void NiStream::Functionf5d400(const std::uint8_t& value)
{
    NiBinaryStream* stream = oStr;
    std::uint32_t size = 1;
    stream->_absoluteCurrentPos += stream->_writeFn(stream, &value, 1, &size, 1);
}
