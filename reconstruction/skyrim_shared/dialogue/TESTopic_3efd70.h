// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESTopic, TESTopic::Function3efd70, BGSDialogueBranch::Function38cf10: GUESS(low)
// BGSDialogueBranch, TESTopic::pOwnerBranch: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSDialogueBranch
{
public:
    std::uint8_t unk00[0x30];
    void* unk30;
    void Function38cf10(class TESTopic* topic);
};

class TESTopic
{
public:
    std::uint8_t unk00[0x38];
    BGSDialogueBranch* pOwnerBranch;
    void Function3efd70(BGSDialogueBranch* branch);
};
