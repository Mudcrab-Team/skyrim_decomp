// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadInitialData.cpp:171
// 0x620870 BGSSaveLoadInitialData::LoadInitialDataStruct
// Adapted bodies: BGSSaveLoadInitialData::LoadInitialDataStruct from the sibling source named above
#include "BGSSaveLoadInitialData_620870.h"

unsigned int BGSSaveLoadInitialData::LoadInitialDataStruct(BGSLoadFormBuffer* a_buffer, INITIAL_DATA_TYPE a_type, void* a_output)
{
    char data[128];
    if (a_type == INITIAL_DATA_NONE)
        return 0;
    a_buffer->LoadDataEndian(data, iInitialDataTypeData[a_type].cSize, 1);
    return LoadInitialDataStruct(data, a_type, a_output);
}
