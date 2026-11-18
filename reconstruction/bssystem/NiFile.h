// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiFile::good: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20: GUESS(low)
#pragma once

#include <cstdint>
#include "NiBinaryStream.h"

class NiFile : public NiBinaryStream
{
public:
    virtual bool good() const;  // compared: 0xeaf5b0

    std::uint8_t unknown20[0x24];  // 20
    // good44: GUESS(low)
    bool good44;  // 44
    std::uint8_t unknown45[0x3];  // 45
};
static_assert(sizeof(NiFile) == 0x48, "NiFile size");
