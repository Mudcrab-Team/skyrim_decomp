// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadInitialData.cpp:171
// BGSSaveLoadInitialData::LoadInitialDataStruct: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadFormBuffer::LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the listing passes a count of one as a third argument
// BGSSaveLoadInitialData, BGSSaveLoadInitialData::iInitialDataTypeData, INITIAL_DATA_TYPE, INITIAL_DATA_NONE, BGSLoadFormBuffer: GUESS(low); the names are the ones the sibling body uses, the layouts come from the listing
// InitialDataTypeData, InitialDataTypeData::cSize: GUESS(low)
#pragma once

enum INITIAL_DATA_TYPE : int
{
    INITIAL_DATA_NONE = 0
};

struct InitialDataTypeData
{
    unsigned char cSize;      // 00
    unsigned char unknown01;  // 01
    unsigned char unknown02;  // 02
};

class BGSLoadFormBuffer
{
public:
    void LoadDataEndian(void* a_data, unsigned int a_size, unsigned int a_count);
};

class BGSSaveLoadInitialData
{
public:
    static unsigned int LoadInitialDataStruct(BGSLoadFormBuffer* a_buffer, INITIAL_DATA_TYPE a_type, void* a_output);
    static unsigned int LoadInitialDataStruct(char* a_buffer, INITIAL_DATA_TYPE a_type, void* a_output);

    static InitialDataTypeData iInitialDataTypeData[];
};
