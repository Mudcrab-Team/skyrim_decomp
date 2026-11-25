// Source exposure: mixed (community names; pinned image observations; sibling symbol declarations).
// Code origin: original; minimal declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysGrowFadeModifier, NiPSysGrowFadeModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// NiPSysModifier, NiPSysModifier::IsEqual, NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_fGrowTime, m_usGrowGeneration, m_fFadeTime, m_usFadeGeneration, m_fBaseScale: SYMBOLS(fo4-pdb) OBSERVED
// unknownBase: GUESS(low); unused inherited storage
#pragma once
#include <cstdint>
class NiObject;
class NiPSysModifier
{
public:
    bool IsEqual(NiObject* other);
    std::uint8_t unknownBase[48];
};
class NiPSysGrowFadeModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* other);
    float m_fGrowTime;
    std::uint16_t m_usGrowGeneration;
    float m_fFadeTime;
    std::uint16_t m_usFadeGeneration;
    float m_fBaseScale;
};
static_assert(sizeof(NiPSysModifier) == 48, "Observed modifier base extent");
