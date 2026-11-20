// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkMemoryAllocator_vtbl; size 0x58
#pragma once
struct hkMemoryAllocator_vtbl {
    void (*_dtor_hkMemoryAllocator)(void);
    void*(*BlockAlloc)(int);
    void (*BlockFree)(void* , int);
    void*(*BufAlloc)(int* );
    void (*BufFree)(void* , int);
    void*(*BufRealloc)(void* , int, int* );
    void (*BlockAllocBatch)(void** , int, int);
    void (*BlockFreeBatch)(void** , int, int);
    void (*GetMemoryStatistics)(char32_t* );
    int (*GetAllocatedSize)(void* , int);
    void (*ResetPeakMemoryStatistics)(void);
};
static_assert(sizeof(hkMemoryAllocator_vtbl) == 88, "hkMemoryAllocator_vtbl layout differs from the PDB");
