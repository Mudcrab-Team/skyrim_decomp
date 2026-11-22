// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0xec3d20 compared function
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSTaskletData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// BSTaskletData::~BSTaskletData: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// unknown08: GUESS(low)
// BSTaskletData::OnStartup: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
#pragma once

#include <cstdint>

class BSTaskletData
{
public:
    BSTaskletData();
    virtual ~BSTaskletData();  // compared: 0x3fb670 (scalar deleting destructor); declared only, rule 18

    bool OnStartup();

    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(BSTaskletData) == 0x10, "BSTaskletData size");
