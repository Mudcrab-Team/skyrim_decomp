// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x6ff1b0 AIProcess::GetDoorActivated
// Adapted bodies: none
// AIProcess::GetDoorActivated: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(tesv-2013-map)
#include "AIProcess_6ff1b0.h"

ObjectRefHandle AIProcess::GetDoorActivated() const
{
    const ObjectRefHandle& handle = high ? high->lastTarget : g_nullHandle;
    return handle;
}
