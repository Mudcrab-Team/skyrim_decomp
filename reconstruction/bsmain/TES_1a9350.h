// Source exposure: mixed (community declarations; local target observations).
// Code origin: original; target behavior and labelled naming sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TES, TES::unk2B0: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; target uses a map pointer at this offset
// NavMeshInfoMap, NavMeshInfoMap::~NavMeshInfoMap: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TES::SetNavMeshInfoMap: CRASHLOGGER_PDB(59818@2026.10.24)
// unmodelledState, g_memoryContext_tls_0x768: GUESS(low); structural state and thread allocation context
#pragma once
#include <cstdint>
class NavMeshInfoMap
{
public:
    virtual ~NavMeshInfoMap();
};
extern __declspec(thread) std::uint32_t g_memoryContext_tls_0x768;
class TES
{
public:
    void SetNavMeshInfoMap(NavMeshInfoMap* map);
    std::uint8_t unmodelledState[0x2B0];
    NavMeshInfoMap* unk2B0;
};
