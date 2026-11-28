// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSBehaviorGraphExtraData, BSBehaviorGraphExtraData::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfeb0d0 BSBehaviorGraphExtraData::RegisterStreamables
#include "BSBehaviorGraphExtraData_feb0d0.h"

// Registers base extra data and the behavior graph filename with the stream.
bool BSBehaviorGraphExtraData::RegisterStreamables(NiStream& a_stream)
{
    bool ok = NiExtraData::RegisterStreamables(a_stream);
    if (ok)
    {
        a_stream.RegisterFixedString(&behaviorGraphFile);
    }
    return ok;
}
