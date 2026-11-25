// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: Stamped as a twin of matched 0x152a9a0 (bsshader/BSEffectShaderProperty_152a9a0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x105bd40 Owner105bd40::Function105bd40
#include "Owner105bd40.h"

// guess: same compiled code as matched 0x152a9a0 apart from relocated fields; its role here is not established.
void Owner105bd40::Function105bd40(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 16;
 stream->_absoluteCurrentPos += stream->_readFn(stream, buffer, count * 16, &size, 1);
}
