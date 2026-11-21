// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing, community declarations and CrashLogger PDB names only
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1474f0 BGSDualCastData::~BGSDualCastData
// Adapted bodies: none
// 0x147420 AutoMemContext::~AutoMemContext
// AutoMemContext, AutoMemContext::~AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
// AutoMemContext::saved, memoryContext_tls_0x768: GUESS(low)
#include "BGSDualCastData.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BGSDualCastData::BGSDualCastData()
{
}

BGSDualCastData::~BGSDualCastData()
{
    ClearData();
}

AutoMemContext::~AutoMemContext()
{
    memoryContext_tls_0x768 = saved;
}
