// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSWindModifier: EXE_RTTI
// strength: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

class NiPSysModifier
{
public:
    NiPSysModifier();
    virtual ~NiPSysModifier();

protected:
    std::uint8_t padding08[0x10];
    std::uint32_t order;
    std::uint8_t padding1C[0x14];
};

class BSWindModifier : public NiPSysModifier
{
public:
    BSWindModifier();

private:
    float strength;
};
static_assert(sizeof(BSWindModifier) == 0x38, "represented layout size");
