// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSFile::~BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown48: GUESS(low)
#pragma once

#include <cstdint>
#include "NiFile.h"

class BSFile : public NiFile
{
public:
    BSFile();
    virtual ~BSFile();  // compared: 0xebeb10 (scalar deleting destructor)

    std::uint8_t unknown48[0x138];  // 48
};
static_assert(sizeof(BSFile) == 0x180, "BSFile size");
