// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadTaskData; size 0x1e8
#pragma once

#include "GArrayLH_RE__GFxTimelineDef__ExecuteTagList_e62d653d.h"
#include "GFxMovieLoadInfo.h"
#include "GHashUncached_RE__GFxResourceID_RE__GFxResourceSource_RE__GFxResourceID__HashOp_d16eba45.h"
#include "GLock.h"
#include "GPtr_RE__GFxLoadUpdateSync_0c3ce186.h"
#include "GString.h"
#include "GStringHash_int_70308b3a.h"
#include "LoadTaskDataBase.h"
struct GFxImportNode;
struct GMemoryHeap;
struct LoadTaskData {
    LoadTaskDataBase _base;
    GMemoryHeap* loadDataHeap;
    GMemoryHeap* imageHeap;
    GString fileURL;
    GFxMovieLoadInfo movieInfo;
    unsigned int fileAttributes;
    unsigned int padC4;
    void* metadata;
    unsigned int metadataSize;
    unsigned int loadStatus;
    int frameLoading;
    unsigned char unkDC;
    unsigned char padDD;
    unsigned short padDE;
    unsigned int unkE0;
    unsigned int padE4;
    GPtr_RE__GFxLoadUpdateSync_0c3ce186 updateSync;
    unsigned long long unkF0;
    unsigned long long unkF8;
    GFxImportNode* importInfoBegin;
    GFxImportNode* importInfoEnd;
    unsigned long long unk110;
    unsigned long long unk118;
    unsigned long long unk120;
    unsigned long long unk128;
    unsigned int importedResourceCount;
    unsigned int pad134;
    GLock resourceLock;
    GHashUncached_RE__GFxResourceID_RE__GFxResourceSource_RE__GFxResourceID__HashOp_d16eba45 resources;
    unsigned long long unk168;
    unsigned long long unk170;
    GLock frameLock;
    GArrayLH_RE__GFxTimelineDef__ExecuteTagList_e62d653d movieFrames;
    GArrayLH_RE__GFxTimelineDef__ExecuteTagList_e62d653d importFrames;
    int importFrameCount;
    unsigned int pad1D4;
    GStringHash_int_70308b3a frameLabels;
    unsigned long long unk1E0;
};
static_assert(sizeof(LoadTaskData) == 488, "LoadTaskData layout differs from the PDB");
