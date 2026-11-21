// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GMemoryHeap; size 0xc8
#pragma once

#include "GListNode_RE__GMemoryHeap_d7198256.h"
#include "GList_RE__GMemoryHeap_db6f51ab.h"
#include "GLock.h"
#include "HeapInfo.h"
struct GMemoryHeap_vtbl;
struct GMemoryHeap {
    GMemoryHeap_vtbl* __vftable;
    GListNode_RE__GMemoryHeap_d7198256 _base_GListNode_RE_GMemoryHeap_;
    unsigned long long _selfSize;
    unsigned int _refCount;
    unsigned int _pad24;
    unsigned long long _ownerThreadID;
    void* _autoRelease;
    HeapInfo _info;
    GList_RE__GMemoryHeap_db6f51ab _childHeaps;
    GLock _heapLock;
    bool _useLocks;
    bool _trackDebugInfo;
    unsigned short _padC2;
    unsigned int _padC4;
};
static_assert(sizeof(GMemoryHeap) == 200, "GMemoryHeap layout differs from the PDB");
