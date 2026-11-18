// Inferred names: GUESS(low)
// Origin: original reconstruction informed by CommonLibSSE-NG declarations (MIT).
// Source exposure: mixed (local binary analysis and pinned public declarations).
// BSReference: EXE_RTTI

// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once
#include <cstdint>
// NiRefObject, _refCount, _pad0C: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiRefObject { public: virtual ~NiRefObject(); volatile std::uint32_t _refCount; std::uint32_t _pad0C; };
// NiObject, SaveBinary: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream;
class NiObject : public NiRefObject { public: void SaveBinary(NiStream&); };
// NiStream, SaveLinkID: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiStream { public: void SaveLinkID(const NiObject*); };
// BSReference, reference: GUESS(low)
// SaveBinary: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class BSReference : public NiObject { public: void SaveBinary(NiStream& stream); NiObject* reference; };
