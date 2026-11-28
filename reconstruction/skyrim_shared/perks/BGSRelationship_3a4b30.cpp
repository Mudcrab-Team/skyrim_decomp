// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSRelationship, BGSRelationship::GetChildAssociationLabel: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x3a4b30 BGSRelationship::GetChildAssociationLabel
#include "BGSRelationship_3a4b30.h"

// Returns the child association label using the second NPC's sex.
const char* BGSRelationship::GetChildAssociationLabel() const
{
    if (npc2 != nullptr && assocType != nullptr)
    {
        return assocType->GetLabel(1, npc2->GetSex());
    }
    return nullptr;
}
