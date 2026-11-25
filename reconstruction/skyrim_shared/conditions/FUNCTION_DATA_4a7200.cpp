// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x4a7200 FUNCTION_DATA::~FUNCTION_DATA
// Adapted bodies: FUNCTION_DATA::~FUNCTION_DATA from fo4-private@1b765c70 src/Shared/AI/TESConditionItem.cpp:5 (see the header)
#include "FUNCTION_DATA_4a7200.h"

FUNCTION_DATA::~FUNCTION_DATA()
{
    unsigned int count = TESParameters::GetParamCount(*this);
    if (count > 2)
        count = 2;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (pParam[i] && TESParameters::GetParamIsString(*this, i))
        {
            BSFixedString* value = static_cast<BSFixedString*>(pParam[i]);
            if (value)
            {
                delete value;
            }
            pParam[i] = nullptr;
        }
    }
}
