// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadInitialData.cpp:180
// 0x6208f0 BGSSaveLoadInitialData::LoadInitialDataStruct
// Adapted bodies: BGSSaveLoadInitialData::LoadInitialDataStruct from the sibling source named above
#include "BGSSaveLoadInitialData_6208f0.h"

unsigned int BGSSaveLoadInitialData::LoadInitialDataStruct(const BGSUnloadedFormBuffer& a_buffer, INITIAL_DATA_TYPE a_type, void* a_output)
{
    char data[128];
    if (a_type == INITIAL_DATA_NONE)
        return 0;
    a_buffer.CopyData(data, iInitialDataTypeData[a_type].cSize);
    return LoadInitialDataStruct(data, a_type, a_output);
}
