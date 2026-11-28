// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0x11ebc40 BSNavmeshTriangleDoorPortal::Write
#include "BSNavmeshTriangleDoorPortal_11ebc40.h"

// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
void BSNavmeshTriangleDoorPortal::Write(BSPathingStreamWrite* a_stream)
{
    a_stream->WriteUInt16(owningTriangleIndex);
    if (door) {
        std::uint32_t type = door->GetType();
        a_stream->WriteUInt32(type);
        door->Write(a_stream);
    } else {
        a_stream->WriteUInt32(0);
    }
}
