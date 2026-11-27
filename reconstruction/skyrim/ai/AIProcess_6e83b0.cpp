// Source exposure: mixed (names and layout from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB layout.
// Adapted bodies: none
// 0x6e83b0 AIProcess::IsWandering
#include "AIProcess_6e83b0.h"

// Returns true when the active package procedure is the wander procedure.
bool AIProcess::IsWandering()
{
    if (currentPackage.package)
    {
        const std::int32_t packageType = currentPackage.package->procedureType;
        const std::int32_t procedureIndex =
            GetRunOncePackage() ? GetRunOnceProcedureIndex() : currentPackage.currentProcedureIndex;
        if (gPackageProcedureTables[packageType][procedureIndex] == 1)
        {
            return true;
        }
    }
    return false;
}
