// Source exposure: mixed (community declarations; pinned-image observations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations using the community interface.
// NiPSysModifier, NiPSysColorModifier: STANDIN GUESS(low); inventory owner and observed base call
// RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown10, colorData: GUESS(low); measured storage, descriptive names
#pragma once
#include "declarations/NiObject.h"
#include <cstdint>

class NiPSysModifier : public NiObject
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    std::uint8_t unknown10[0x20];
};
static_assert(sizeof(NiPSysModifier) == 0x30, "observed base extent");
class NiPSysColorModifier : public NiPSysModifier
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    NiObject* colorData;
};
