// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: Stamped as a twin of matched 0x152a9d0 (bsshader/BSEffectShaderProperty_152a9a0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x10aacc0 Owner10aacc0::Function10aacc0
#include "Owner10aacc0.h"

// guess: same compiled code as matched 0x152a9d0 apart from relocated fields; its role here is not established.
void Owner10aacc0::Function10aacc0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 16;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, count * 16, &size, 1);
}
