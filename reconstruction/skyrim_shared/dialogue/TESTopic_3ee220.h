// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESTopic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESTopic::GetDialogueSubtypeFrom4CC: SYMBOLS(tesv-2013-map) SYMBOLS(fo4-pdb)
#pragma once

#include <cstdint>

class TESTopic
{
public:
    static std::uint32_t GetDialogueSubtypeFrom4CC(std::uint32_t fourCC);
};
