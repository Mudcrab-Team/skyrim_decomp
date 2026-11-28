// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// ScrapHeap, ScrapHeap::GetSuccessor: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xcdff10 ScrapHeap::GetSuccessor
#include "ScrapHeap_cdff10.h"

// Returns the next contiguous heap block header, or null at the last block.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
Block* ScrapHeap::GetSuccessor(Block* a_block) const
{
    if (a_block == lastBlock)
    {
        return nullptr;
    }
    std::size_t payloadSize = a_block->sizeFlags & 0x3FFFFFFFFFFFFFFFULL;
    return reinterpret_cast<Block*>(reinterpret_cast<std::uintptr_t>(a_block) + payloadSize + sizeof(Block));
}
