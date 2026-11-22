// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial terrain manager layout.
// BGSTerrainManager, unk36: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// QueryCurrentTerrainFlag: GUESS(low)
#pragma once

#include <cstdint>

class BGSTerrainManager
{
public:
    static bool QueryCurrentTerrainFlag();

private:
    std::uint8_t unknown00[0x36];
    std::uint8_t unk36;
};
