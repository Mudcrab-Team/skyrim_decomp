// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using the cited names and partial base declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysResetOnLoopCtlr: GUESS(low)
// Class spelling follows the qualified Address Library names.
// NiPSysResetOnLoopCtlr::~NiPSysResetOnLoopCtlr: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// padding08: GUESS(low)
#pragma once

#include <cstdint>

class NiTimeController
{
public:
    virtual ~NiTimeController();

private:
    std::uint8_t padding08[0x40];
};

class NiPSysResetOnLoopCtlr : public NiTimeController
{
public:
    NiPSysResetOnLoopCtlr();
    ~NiPSysResetOnLoopCtlr() override = default;

private:
    std::uint8_t padding48[0x8];
};
static_assert(sizeof(NiPSysResetOnLoopCtlr) == 0x50, "measured allocation size");
