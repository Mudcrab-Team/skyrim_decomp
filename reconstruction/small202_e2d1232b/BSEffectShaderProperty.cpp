// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BSEffectShaderProperty: STANDIN GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x152a9a0 BSEffectShaderProperty::Function152a9a0
// 0x152a9d0 BSEffectShaderProperty::Function152a9d0
#include "BSEffectShaderProperty.h"
void BSEffectShaderProperty::Function152a9a0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 16;
 stream->_absoluteCurrentPos += stream->_readFn(stream, buffer, count * 16, &size, 1);
}

void BSEffectShaderProperty::Function152a9d0(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 16;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, count * 16, &size, 1);
}
