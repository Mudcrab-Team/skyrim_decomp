// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// NiPathInterpolator: STANDIN GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xf66e30 NiPathInterpolator::Functionf66e30
// 0xf66eb0 NiPathInterpolator::Functionf66eb0
// 0xf66ee0 NiPathInterpolator::Functionf66ee0
#include "NiPathInterpolator.h"
void NiPathInterpolator::Functionf66e30(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 2;
 stream->_absoluteCurrentPos += stream->_readFn(stream, buffer, count * 2, &size, 1);
}

void NiPathInterpolator::Functionf66eb0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 2;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, count * 2, &size, 1);
}

void NiPathInterpolator::Functionf66ee0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 4;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, size, &size, 1);
}
