// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESTopicInfo::SetAltered follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/testopicinfo.cpp:866
// TESTopicInfo, TESTopicInfo::SetAltered, parentTopic, TESForm, TESForm::SetAltered, formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTopic: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TestBit: GUESS(low)
#pragma once

#include <cstdint>
#include "skyrim_shared/forms/TESForm.h"

class TESTopic : public TESForm
{};

class TESTopicInfo : public TESForm
{
public:
    void SetAltered(bool a_set) override;

    TESTopic* parentTopic;
};
