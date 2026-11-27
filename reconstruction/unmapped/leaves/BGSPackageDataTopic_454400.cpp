// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/BGSPackageDataTopic.cpp:47
// 0x454400 BGSPackageDataTopic::Assign
// Adapted bodies: BGSPackageDataTopic::Copy from the sibling source named above
#include "BGSPackageDataTopic_454400.h"

void BGSPackageDataTopic::Assign(const IPackageData* a_other)
{
    const BGSPackageDataTopic* topic = dynamic_cast<const BGSPackageDataTopic*>(a_other);
    if (topic)
        data.Copy(&topic->data);
}
