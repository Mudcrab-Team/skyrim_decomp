// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GMemoryHeap_vtbl; size 0x118
#pragma once
struct GMemoryHeap_vtbl {
    void (*_dtor_GMemoryHeap)(void);
    void (*CreateArena)(char32_t* , char32_t* );
    void (*DestroyArena)(char32_t* );
    bool (*ArenaIsEmpty)(char32_t* );
    char32_t*(*CreateHeap)(unsigned char* , char32_t* );
    void (*SetLimitHandler)(char32_t* );
    void (*SetLimit)(char32_t* );
    unsigned int (*AddRef)(void);
    unsigned int (*Release)(void);
    void*(*Alloc)(unsigned long long, unsigned long long);
    void*(*Alloc_2)(unsigned long long, unsigned long long);
    void*(*Realloc)(void* , char32_t* );
    bool (*Free)(void* , unsigned long long, unsigned long long);
    void*(*AllocAutoHeap)(void* , char32_t* );
    void*(*AllocAutoHeap_2)(void* , char32_t* );
    char32_t*(*GetAllocHeap)(void* );
    void (*GetUsableSize)(void* );
    void*(*AllocSysDirect)(unsigned long long, unsigned long long, unsigned long long* , unsigned long long* );
    bool (*FreeSysDirect)(void* , unsigned long long, unsigned long long);
    void (*GetStats)(char32_t* , bool);
    unsigned long long (*GetFootprint)(void);
    void (*GetTotalFootprint)(void);
    unsigned long long (*GetUsedSpace)(void);
    void (*GetTotalUsedSpace)(void);
    void (*GetRootStats)(char32_t* );
    void (*VisitMem)(char32_t* );
    void (*VisitRootSegments)(char32_t* );
    void (*VisitHeapSegments)(char32_t* );
    void (*SetTracer)(char32_t* );
    void (*DestroyItself)(void);
    void (*UltimateCheck_Internal)(void);
    void (*ReleaseCachedMem)(void);
    bool (*DumpMemoryLeaks_Internal)(void);
    void (*CheckIntegrity_Internal)(void);
    void (*GetUserDebugStats)(char32_t* );
};
static_assert(sizeof(GMemoryHeap_vtbl) == 280, "GMemoryHeap_vtbl layout differs from the PDB");
