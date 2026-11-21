// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMemorySystem_vtbl; size 0xb8
#pragma once

#include "hkResult.h"
struct hkMemorySystem_vtbl {
    void (*_dtor_hkMemorySystem)(void);
    char32_t*(*MainInit)(char32_t* , char32_t* );
    hkResult (*MainQuit)(char32_t* );
    void (*ThreadInit)(char32_t* , unsigned char* , char32_t* );
    void (*ThreadQuit)(char32_t* , char32_t* );
    hkResult (*SetHeapSoftLimit)(int);
    int (*GetHeapSoftLimit)(void);
    bool (*SolverCanAllocSingleBlock)(int);
    bool (*HeapCanAllocTotal)(int);
    void (*PrintStatistics)(char32_t* );
    char32_t*(*GetUncachedLockedHeapAllocator)(void);
    void (*GetHeapStatistics)(char32_t* );
    hkResult (*WalkMemory)(char32_t* , void* );
    void (*GarbageCollectThread)(char32_t* );
    void (*GarbageCollectShared)(void);
    void (*GarbageCollect)(void);
    void (*AdvanceFrame)(void);
    void*(*DebugFindBaseAddress)(void* , int);
    hkResult (*GetMemorySnapshot)(char32_t* );
    void (*DebugLockBaseAddress)(void* );
    void (*DebugUnlockBaseAddress)(void* );
    void (*DebugTagAddress)(void* , void* );
    hkResult (*GetAllocationCallStack)(void* , unsigned long long* , int* , unsigned long long* );
};
static_assert(sizeof(hkMemorySystem_vtbl) == 184, "hkMemorySystem_vtbl layout differs from the PDB");
