// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageDataRef.cpp:135
// 0x453d40 BGSPackageDataRef::RemapInterruptData
// Adapted bodies: BGSPackageDataRef::RemapInterruptData from the sibling source named above
#include "BGSPackageDataRef_453d40.h"

void BGSPackageDataRef::RemapInterruptData(PACK_INTERRUPT_TARGET a_target, PACK_INTERRUPT_LOCATION, PointerHandleCopy a_ref)
{
    if (pointer->GetTargType() == 5 && pointer->GetTargInterruptData() == static_cast<std::int32_t>(a_target)) {
        pointer->SetTargType(0);
        pointer->SetTargReference(a_ref);
    }
}
