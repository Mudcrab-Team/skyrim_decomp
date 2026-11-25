// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSAIOpsMeter.cpp:137
// 0x4478e0 BGSAIOperationsMeter::CheckPermissionForPathing
// Adapted bodies: BGSAIOperationsMeter::CheckPermissionForPathing from the sibling source named above
#include "BGSAIOperationsMeter_4478e0.h"

bool BGSAIOperationsMeter::CheckPermissionForPathing()
{
    if (pathRequestsAllowedThisFrame >= pathRequestsAllowedPerFrame) {
        if (PlayerCharacter::singleton->IsSleepingorResting())
            return true;
        ++pathRequestsDeniedThisFrame;
        ++pathRequestsDeniedTotal;
        return false;
    }
    return true;
}
