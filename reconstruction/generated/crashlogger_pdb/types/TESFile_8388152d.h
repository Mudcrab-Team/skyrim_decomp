// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFile; size 0x4c8
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSimpleList_unsigned_long_long_a42a978c_fcccbf99.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "Error.h"
#include "FILETIME_7813ec6f.h"
#include "FORM.h"
#include "RE__BSSimpleList_char_8b0a3a12.h"
#include "RecordFlag.h"
#include "WIN32_FIND_DATAA.h"
struct BSFile;
struct TESBitArrayFile;
struct TESObjectCELL_f81013b3;
struct TESFile_8388152d {
    Error lastError;
    unsigned int pad004;
    TESFile_8388152d* threadSafeParent;
    void* threadSafeFileMap;
    unsigned long long unk018;
    unsigned long long unk020;
    unsigned char unk028;
    bool unk029;
    unsigned short pad02A;
    unsigned int pad02C;
    BSFile* lockedFile;
    BSFile* file;
    TESBitArrayFile* formUserDataBitArray;
    TESBitArrayFile* formVersionBitArray;
    TESBitArrayFile* formIDBitArray;
    unsigned char fileName[260];
    unsigned char path[260];
    unsigned char* buffer;
    unsigned int bufferAllocSize;
    unsigned int firstCellOffset;
    unsigned int currCellOffset;
    unsigned int unk274;
    TESObjectCELL_f81013b3* currCell;
    unsigned int currRefOffset;
    FORM currentform;
    unsigned int currentchunkID;
    unsigned int actualChunkSize;
    unsigned int filesize;
    unsigned int fileOffset;
    unsigned int formoffset;
    unsigned int chunkoffset;
    FORM saveform;
    unsigned int saveFormOffset;
    unsigned long long saveChunkOffset;
    unsigned long long unk2D8;
    unsigned long long unk2E0;
    unsigned char unk2E8;
    bool isBigEndian;
    unsigned char unk2EA;
    unsigned char pad2EB;
    WIN32_FIND_DATAA fileData;
    float version;
    unsigned int formCount;
    unsigned int nextFormID;
    RecordFlag recordFlags;
    unsigned int pad43C;
    RE__BSSimpleList_char_8b0a3a12 masters;
    BSSimpleList_unsigned_long_long_a42a978c_fcccbf99 mastersData;
    unsigned int masterCount;
    unsigned int pad464;
    TESFile_8388152d** masterPtrs;
    FILETIME_7813ec6f deletedFormTime;
    unsigned char compileIndex;
    unsigned char pad479;
    unsigned short smallFileCompileIndex;
    unsigned int pad47C;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce createdBy;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce summary;
    unsigned char* decompressedFormBuffer;
    unsigned int decompressedFormBufferSize;
    unsigned int pad4AC;
    void* reservedDecompressionBuffer;
    unsigned int reservedDecompressionBufferSize;
    unsigned int pad4BC;
    void* interiorCellOffsetData;
};
static_assert(sizeof(TESFile_8388152d) == 1224, "TESFile_8388152d layout differs from the PDB");
