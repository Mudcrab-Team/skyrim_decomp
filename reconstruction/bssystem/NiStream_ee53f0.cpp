// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream::GetNumberOfLinkIDs: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xee53f0 NiStream::GetNumberOfLinkIDs
#include "NiStream_ee53f0.h"

// Return the next link ID count from the thread-local link table and advance the cursor.
std::uint32_t NiStream::GetNumberOfLinkIDs()
{
    const std::uint32_t index = linkIdIndex++;
    return gLinkIdList_tls_0x9b8->counts[index];
}
