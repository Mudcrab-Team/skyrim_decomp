// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSStream: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSStream::Functionee5310: GUESS(low)
// 0xee5310 BSStream::Functionee5310
#include "BSStream_ee5310.h"

// Read a link ID from the stream and resolve it to the loaded object table.
NiObject* BSStream::Functionee5310()
{
    std::uint32_t linkId;
    iStr->Read(&linkId);
    if (linkId == 0xFFFFFFFFu) {
        return nullptr;
    }
    return objects[linkId];
}
