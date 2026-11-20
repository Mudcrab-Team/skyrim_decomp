// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSTaskletData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSTaskletData::~BSTaskletData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>

class BSTaskletData
{
public:
    BSTaskletData();
    virtual ~BSTaskletData();  // compared: 0x3fb670 (scalar deleting destructor); declared only, rule 18

    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(BSTaskletData) == 0x10, "BSTaskletData size");
