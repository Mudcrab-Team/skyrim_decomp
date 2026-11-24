// Source exposure: mixed (community headers, CrashLogger layouts, sibling game code, the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Code origin: adapted from the sibling bodies named in the header; names and prototypes as labelled there
// 0x223770 GetHighestPriority
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GlobalFunc.cpp:21
#include "NiInterpController_223770.h"

int GetHighestPriority(NiAVObject* apRoot, NiAVObject* apObj)
{
    if (!apRoot)
        return 0;
    if (!apObj)
        return 0;
    NiTimeController* controller = apRoot->GetController(&NiMultiTargetTransformController::ms_RTTI);
    if (!controller)
        return 0;
    NiMultiTargetTransformController* multi = static_cast<NiMultiTargetTransformController*>(controller);
    for (unsigned short i = 0; i < multi->numInterps; ++i)
    {
        if (multi->targets[i] == apObj)
        {
            if (i != NiInterpController::INVALID_INDEX)
                return *(char*)((char*)multi->blendInterps + 72 * i + 0x1C);
            return 0;
        }
    }
    return 0;
}
