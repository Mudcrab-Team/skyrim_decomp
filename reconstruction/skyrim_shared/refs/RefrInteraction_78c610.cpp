// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// RefrInteraction: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x78c610 RefrInteraction::operator==
// CI hash: 0x78c610 ??8RefrInteraction@@QEBA_NAEBQEBV0@@Z
#include "RefrInteraction_78c610.h"

// Compares target handle, actor handle, and virtual interaction type.
bool RefrInteraction::operator==(const RefrInteraction* const& a_rhs) const
{
    const RefrInteraction* other = a_rhs;
    if (targetRefr != other->targetRefr)
    {
        return false;
    }
    if (actor != other->actor)
    {
        return false;
    }
    std::uint32_t otherType = other->GetType();
    if (GetType() != otherType)
    {
        return false;
    }
    return true;
}
