// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BSPCOrbisGamepadDevice: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// scePadClose: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstddef>
#include <cstdint>

class BSPCOrbisGamepadDevice
{
public:
    virtual void Release();

    std::uint8_t padding08[0xC0];
    std::int32_t userIndex;
};
static_assert(offsetof(BSPCOrbisGamepadDevice, userIndex) == 0xC8, "observed userIndex offset");

int scePadClose(std::int32_t);
