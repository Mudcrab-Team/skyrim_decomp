// Type declarations for the BSPathingCell translation unit (build sse-steam-1-7-104).
//
// Labels: v2
// Code origin: original reconstruction from binary analysis by Taylor Turner, assisted by claude-sonnet-5-5; class and member names come from CommonLibSSE-NG (MIT); no external implementation body is copied, and the member offsets and types of the community-named members follow the community declaration.
// Source exposure: binary-analysis (a local listing of the contributor's own copy of the pinned image).
// Community names are unverified. Only the members the compared code needs are declared.
// BSPathingCell, BSPathingCell::BSPathingCell, BSPathingCell::~BSPathingCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// _refCount, unk0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); names and offsets as declared there, the BSIntrusiveRefCounted base is flattened into this class and the types are guesses
// The MIT notice below covers only the names and declarations taken from
// CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; the other code in this file
// is covered by the repository licence and the provenance labels above.
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

class BSPathingCell {
public:
    BSPathingCell();
    virtual ~BSPathingCell() {}  // compared: 0x4e0860 (scalar deleting destructor)

    std::uint32_t _refCount;  // 08
    std::uint32_t unk0C;      // 0C
};
static_assert(sizeof(BSPathingCell) == 0x10, "BSPathingCell size");
