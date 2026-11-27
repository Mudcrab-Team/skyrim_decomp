// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadInitialData.cpp:180
// BGSSaveLoadInitialData::LoadInitialDataStruct, BGSUnloadedFormBuffer::CopyData: SIBLING(fo4-private@1b765c70, author-permission)
// BGSSaveLoadInitialData, BGSSaveLoadInitialData::iInitialDataTypeData, BGSUnloadedFormBuffer, INITIAL_DATA_TYPE, INITIAL_DATA_NONE, InitialDataTypeData, InitialDataTypeData::cSize: GUESS(low); the names are the ones the sibling body uses, the layouts come from the listing
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

class BGSUnloadedFormBuffer
{
public:
    void CopyData(void* a_dst, unsigned int a_size) const;
};

class BGSSaveLoadInitialData
{
public:
    static unsigned int LoadInitialDataStruct(const BGSUnloadedFormBuffer& a_buffer, INITIAL_DATA_TYPE a_type, void* a_output);
    static unsigned int LoadInitialDataStruct(char* a_buffer, INITIAL_DATA_TYPE a_type, void* a_output);

    static InitialDataTypeData iInitialDataTypeData[];
};
