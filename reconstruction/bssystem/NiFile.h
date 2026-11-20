// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: original; the listing and community declarations only
// NiFile::size, file: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG types file as std::FILE*, kept as an untyped handle here
// unknown20, unknown28, unknown30, unknown40: GUESS(low); words the compared functions do not read, at their measured offsets
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
    virtual std::uint32_t size() const;  // compared: 0xeadd20

    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    void* file;  // 38
    std::uint32_t unknown40;  // 40
    // good44: GUESS(low)
    bool good44;  // 44
    std::uint8_t unknown45[0x3];  // 45
};
static_assert(sizeof(NiFile) == 0x48, "NiFile size");
