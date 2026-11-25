// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:5
// FUNCTION_DATA, FUNCTION_DATA::~FUNCTION_DATA, TESParameters::GetParamCount, TESParameters::GetParamIsString: SIBLING(fo4-private@1b765c70, author-permission)
// FUNCTION_DATA::pParam, TESParameters, BSFixedString: GUESS(medium); names from the sibling body, FUNCTION_DATA::params is the community name for the same member
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BSFixedString
{
public:
    ~BSFixedString();

    const char* data;  // 00
};

struct FUNCTION_DATA;

namespace TESParameters
{
    unsigned int GetParamCount(FUNCTION_DATA& a_data);
    bool GetParamIsString(FUNCTION_DATA& a_data, unsigned int a_index);
}

struct FUNCTION_DATA
{
    ~FUNCTION_DATA();

    std::uint8_t unknown00[0x8];  // 00
    void* pParam[2];              // 08
};
static_assert(sizeof(FUNCTION_DATA) == 0x18, "FUNCTION_DATA size");
