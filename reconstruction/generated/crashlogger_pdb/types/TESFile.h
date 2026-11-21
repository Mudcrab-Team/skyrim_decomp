// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFile; size 0x4c8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSimpleList_unsigned_long_long_a42a978c.h"
#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "EnumSet_RE__TESFile__Error_unsigned_int_6562516a.h"
#include "EnumSet_RE__TESFile__RecordFlag_unsigned_int_b72e005b.h"
#include "FILETIME.h"
#include "FORM_bc455ae9.h"
#include "RE__BSSimpleList_char_8b0a3a12.h"
#include "WIN32_FIND_DATAA.h"
struct BSFile;
struct BSFixedString;
struct TESBitArrayFile;
struct TESObjectCELL;
struct TESFile {
    EnumSet_RE__TESFile__Error_unsigned_int_6562516a lastError;
    unsigned int pad004;
    TESFile* threadSafeParent;
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
    TESObjectCELL* currCell;
    unsigned int currRefOffset;
    FORM_bc455ae9 currentform;
    unsigned int currentchunkID;
    unsigned int actualChunkSize;
    unsigned int filesize;
    unsigned int fileOffset;
    unsigned int formoffset;
    unsigned int chunkoffset;
    FORM_bc455ae9 saveform;
    unsigned int saveFormOffset;
    unsigned long long saveChunkOffset;
    BSFixedString* fld2D8;
    BSFixedString* fld2E0;
    unsigned char unk2E8;
    bool isBigEndian;
    unsigned char unk2EA;
    unsigned char pad2EB;
    WIN32_FIND_DATAA fileData;
    float version;
    unsigned int formCount;
    unsigned int nextFormID;
    EnumSet_RE__TESFile__RecordFlag_unsigned_int_b72e005b recordFlags;
    unsigned int pad43C;
    RE__BSSimpleList_char_8b0a3a12 masters;
    BSSimpleList_unsigned_long_long_a42a978c mastersData;
    unsigned int masterCount;
    unsigned int pad464;
    TESFile** masterPtrs;
    FILETIME deletedFormTime;
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
static_assert(sizeof(TESFile) == 1224, "TESFile layout differs from the PDB");
