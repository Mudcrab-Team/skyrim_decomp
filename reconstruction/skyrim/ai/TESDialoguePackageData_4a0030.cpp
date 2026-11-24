// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a0030 TESDialoguePackageData::TESDialoguePackageData
// Adapted bodies: TESDialoguePackageData::TESDialoguePackageData from fo4-private@1b765c70 src/Shared/AI/PackageDataDialogue.cpp:57 (see the header)
#include "TESDialoguePackageData_4a0030.h"

TESDialoguePackageData::TESDialoguePackageData(PACK_DIALOGUE_DATA a_data)
{
    fFov = a_data.fFov;
    bNOHeadtracking = a_data.bNOHeadtracking;
    ptopic = reinterpret_cast<TESTopic*>(static_cast<std::uintptr_t>(a_data.iTopicID));  // the plugin record holds a form ID, resolved later
    fDistanceStartTalking = a_data.fDistanceStartTalking;
    pTargetLocation = nullptr;
    bDoNotControlTarget = a_data.bDoNotControlTarget;
    bSayTo = a_data.bSayTo;
    eTriggerType = a_data.eTriggerType;
}
