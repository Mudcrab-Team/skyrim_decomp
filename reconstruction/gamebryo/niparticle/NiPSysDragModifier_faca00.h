// Source exposure: mixed (community declarations and the pinned image).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysDragModifier, NiPSysDragModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifier::IsEqual: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_pkDragObj, m_kDragAxis, m_fPercentage, m_fRange, m_fFalloff: SYMBOLS(fo4-pdb)
// unknown10: GUESS(low)
#pragma once
#include <cstddef>
#include <cstdint>
#include "declarations/NiObject.h"

class NiPSysModifier : public NiObject
{
public:
    bool IsEqual(NiObject* object) override;
    std::uint8_t unknown10[0x20];
};

class NiPSysDragModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiObject* object) override;
    NiObject* m_pkDragObj;
    float m_kDragAxis[3];
    float m_fPercentage;
    float m_fRange;
    float m_fFalloff;
};
static_assert(offsetof(NiPSysDragModifier, m_pkDragObj) == 0x30, "m_pkDragObj offset");
static_assert(offsetof(NiPSysDragModifier, m_kDragAxis) == 0x38, "m_kDragAxis offset");
static_assert(sizeof(NiPSysDragModifier) == 0x50, "drag modifier size");
