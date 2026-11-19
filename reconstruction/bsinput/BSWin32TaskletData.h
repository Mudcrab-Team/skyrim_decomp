// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BSWin32TaskletData, BSWin32TaskletData::~BSWin32TaskletData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI; the class name is in NG's RTTI and VTABLE offset lists, NG declares no class
// unknown10, unknown18, unknown20: GUESS(low); the compared destructor reads none of them
#pragma once

#include <cstdint>
#include <cstddef>
#include "bscore/BSTaskletData.h"

class BSWin32TaskletData : public BSTaskletData
{
public:
    virtual ~BSWin32TaskletData();  // compared: 0x3fb6b0  // slot 00
    BSWin32TaskletData();

    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
};
static_assert(sizeof(BSWin32TaskletData) == 0x28, "BSWin32TaskletData size");
