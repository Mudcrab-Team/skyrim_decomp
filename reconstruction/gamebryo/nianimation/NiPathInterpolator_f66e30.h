// Origin: adapted NiBinaryStream prefix declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// NiPathInterpolator: STANDIN GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// NiBinaryStream, _absoluteCurrentPos, _pad0C, _readFn, _writeFn, ReadFn, WriteFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiPathInterpolator, Functionf66e30, Functionf66eb0, Functionf66ee0: STANDIN GUESS(low)
class NiBinaryStream {
public:
 virtual ~NiBinaryStream();
 using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
 using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
 std::uint32_t _absoluteCurrentPos;
 std::uint32_t _pad0C;
 ReadFn* _readFn;
 WriteFn* _writeFn;
};
class NiPathInterpolator { public:
 static void Functionf66e30(NiBinaryStream* stream, void* buffer, std::uint32_t count);
 static void Functionf66eb0(NiBinaryStream* stream, void* buffer, std::uint32_t count);
 static void Functionf66ee0(NiBinaryStream* stream, void* buffer, std::uint32_t count);
};
