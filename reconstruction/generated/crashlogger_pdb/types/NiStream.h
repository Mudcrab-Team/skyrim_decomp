// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiStream; size 0x620
#pragma once

#include "BSStreamHeader.h"
#include "BSTArray_RE__NiObjectGroup_RE__BSTSmallArrayHeapAllocator_32_c2a575f5.h"
#include "NiTLargeObjectArray_RE__NiPointer_RE__NiObject_ced29133.h"
#include "NiTLargeObjectArray_RE__detail__BSFixedString_char_81195e51.h"
#include "NiTLargePrimitiveArray_unsigned_int_3b7cfe8b.h"
#include "RE__NiTPointerMap_RE__NiObject_unsigned_int_de35a889.h"
struct NiBinaryStream;
struct NiStream_vtbl;
struct NiStream {
    NiStream_vtbl* __vftable;
    BSStreamHeader header;
    BSTArray_RE__NiObjectGroup_RE__BSTSmallArrayHeapAllocator_32_c2a575f5 groups;
    unsigned int nifMaxVersion;
    unsigned int nifMaxUserDefinedVersion;
    unsigned char inputFilePath[260];
    unsigned short unk20C;
    unsigned short unk20E;
    unsigned long long unk210;
    NiTLargeObjectArray_RE__NiPointer_RE__NiObject_ced29133 objects;
    NiTLargePrimitiveArray_unsigned_int_3b7cfe8b objectSizes;
    NiTLargeObjectArray_RE__NiPointer_RE__NiObject_ced29133 topObjects;
    NiTLargeObjectArray_RE__detail__BSFixedString_char_81195e51 fixedStrings;
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;
    unsigned int linkIndex;
    unsigned int linkBlockIndex;
    RE__NiTPointerMap_RE__NiObject_unsigned_int_de35a889 registerMap;
    unsigned short niAVObjectFlags;
    unsigned short niTimeControllerFlags;
    unsigned short niPropertyFlags;
    unsigned char undefined_2d6[2];
    unsigned int unk2D8;
    bool unk2DC;
    unsigned char undefined_2dd[3];
    unsigned int load;
    unsigned int link;
    unsigned int postLink;
    unsigned char undefined_2ec[4];
    unsigned long long unk2F0;
    unsigned long long unk2F8;
    unsigned int unk300;
    unsigned int unk304;
    int unk308;
    unsigned char lastLoadedRTTI[260];
    unsigned int lastError;
    unsigned char lastErrorMessage[260];
    unsigned char filePath_raw[264];
};
static_assert(sizeof(NiStream) == 1568, "NiStream layout differs from the PDB");
