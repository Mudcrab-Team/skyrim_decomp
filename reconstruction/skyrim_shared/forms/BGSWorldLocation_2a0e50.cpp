// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSWorldLocation, BGSWorldLocation::GetCellOrWorld: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x2a0e50 BGSWorldLocation::GetCellOrWorld
#include "BGSWorldLocation_2a0e50.h"

// Splits the stored location form into either a worldspace or a cell output pointer.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool BGSWorldLocation::GetCellOrWorld(TESObjectCELL** a_outCell, TESWorldSpace** a_outWorld) const
{
    TESForm* form = location;
    if (form == nullptr)
    {
        return false;
    }

    if (form->formType == 0x47)
    {
        *a_outWorld = static_cast<TESWorldSpace*>(form);
        *a_outCell = nullptr;
        return true;
    }

    if (form->formType == 0x3C)
    {
        *a_outCell = static_cast<TESObjectCELL*>(form);
        *a_outWorld = nullptr;
        return true;
    }

    return false;
}
