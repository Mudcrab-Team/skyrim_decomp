// Source exposure: mixed (community declarations, symbol layouts, pinned-image observations).
// Code origin: original; body reconstructed from local target observations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTimeController::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiFloatController, NiFloatController::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFloatController layout, m_uiLastIdx, m_spFloatData: SYMBOLS(fo4-pdb)
// NiFloatData: STANDIN SYMBOLS(fo4-pdb); pointer type from the symbol layout, virtual behavior observed locally
#pragma once
#include "declarations/NiObject.h"
#include <cstddef>
#include <cstdint>

class NiTimeController : public NiObject
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    std::uint16_t flags;
    float frequency;
    float phase;
    float loKeyTime;
    float hiKeyTime;
    float startTime;
    float lastTime;
    float weightedLastTime;
    float scaledTime;
    NiObject* target;
    NiTimeController* next;
};
static_assert(sizeof(NiTimeController) == 0x48, "controller size");
class NiFloatData : public NiObject {};
class NiFloatController : public NiTimeController
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    std::uint32_t m_uiLastIdx;
    NiFloatData* m_spFloatData;
};
static_assert(offsetof(NiFloatController, m_spFloatData) == 0x50, "float data offset");
