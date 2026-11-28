// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xce01d0 ScrapHeap::dtor_deleting
// CI hash: 0xce01d0 ??_GScrapHeap@@UEAAPEAXI@Z
#include "ScrapHeap_ce01d0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
ScrapHeap::ScrapHeap()
{
}

// Releases the reserved virtual memory region before destroying IMemoryStore.
ScrapHeap::~ScrapHeap()
{
    VirtualFree(baseAddress, 0, 0x8000);
}
