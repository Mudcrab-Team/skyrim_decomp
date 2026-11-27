// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiBoolInterpolator, SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// m_bBoolValue, m_spBoolData: SYMBOLS(fo4-pdb)
// NiKeyBasedInterpolator: STANDIN GUESS(low)
// unknown10, unknown19: STANDIN GUESS(low)
#pragma once
#include "../nimain/NiObjectNET.h"
class NiKeyBasedInterpolator : public NiObject {
public:
    void SaveBinary(NiStream& stream);
    std::uint8_t unknown10[8];
};
class NiBoolInterpolator : public NiKeyBasedInterpolator {
public:
    void SaveBinary(NiStream& stream);
    std::uint8_t m_bBoolValue;
    std::uint8_t unknown19[7];
    NiObject* m_spBoolData;
};
static_assert(offsetof(NiBoolInterpolator, m_bBoolValue) == 0x18, "bool value offset");
static_assert(offsetof(NiBoolInterpolator, m_spBoolData) == 0x20, "bool data offset");
