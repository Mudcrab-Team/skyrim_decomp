// Source exposure: mixed (community names; pinned image observations; sibling symbol declarations).
// Code origin: original; minimal declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysBoundUpdateModifier, NiPSysBoundUpdateModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// NiPSysModifier, NiPSysModifier::IsEqual: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_sUpdateSkip: SYMBOLS(fo4-pdb) OBSERVED
#pragma once
#include <cstdint>
class NiObject;
class NiPSysModifier
{
public:
    bool IsEqual(NiObject* other);
    std::uint8_t unknownBase[48];
};
class NiPSysBoundUpdateModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* other);
    std::int16_t m_sUpdateSkip;
};
static_assert(sizeof(NiPSysModifier) == 48, "Observed modifier base extent");
