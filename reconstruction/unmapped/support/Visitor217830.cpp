// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x217830 Visitor217830::Visit
// Adapted bodies: none
#include "Visitor217830.h"

// PDB: the CrashLogger PDB name is a lambda call operator; the stand-in name here is kept.
// Forward the visitor to the node's target object when present.
std::uint32_t Visitor217830::Visit(VisitorNode217830* node)
{
    VisitorTarget217830* target = node->target;
    if (target)
    {
        target->Accept(this);
    }
    return 0;
}
