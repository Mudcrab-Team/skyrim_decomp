// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x18f360 ExtraInfoGeneralTopic::~ExtraInfoGeneralTopic (scalar deleting destructor)
// Adapted bodies: ExtraInfoGeneralTopic::~ExtraInfoGeneralTopic follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1996
#include "ExtraInfoGeneralTopic_18f360.h"

ExtraInfoGeneralTopic::ExtraInfoGeneralTopic() : unk10(nullptr)
{
    next = nullptr;
}

ExtraInfoGeneralTopic::~ExtraInfoGeneralTopic()
{
    unk10->unk48 = false;
    delete unk10;
}
