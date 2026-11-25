// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Code origin: Stamped as a twin of matched 0xf66eb0 (gamebryo/nianimation/NiPathInterpolator_f66e30): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xee8650 Owneree8650::Functionee8650
#include "Owneree8650.h"

// guess: same compiled code as matched 0xf66eb0 apart from relocated fields; its role here is not established.
void Owneree8650::Functionee8650(NiBinaryStream* stream, void* buffer, std::uint32_t count) {
 std::uint32_t size = 2;
 stream->_absoluteCurrentPos += stream->_writeFn(stream, buffer, count * 2, &size, 1);
}
