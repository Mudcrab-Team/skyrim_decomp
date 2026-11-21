// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiAllocator_vtbl; size 0x50
#pragma once

#include "NiMemEventType.h"
struct NiAllocator_vtbl {
    void (*_dtor_NiAllocator)(void);
    void*(*Allocate)(unsigned long long, unsigned int);
    void (*Deallocate)(void* , unsigned int);
    void*(*Reallocate)(void* , unsigned long long* , unsigned long long* , NiMemEventType, bool, unsigned long long, unsigned char* , int, unsigned char* );
    bool (*TrackAllocate)(void* , unsigned long long, NiMemEventType, unsigned char* , int, unsigned char* );
    bool (*TrackDeallocate)(void* , NiMemEventType);
    void (*Unk_06)(void);
    void (*Initialize)(void);
    void (*Shutdown)(void);
    bool (*VerifyAddress)(void* );
};
static_assert(sizeof(NiAllocator_vtbl) == 80, "NiAllocator_vtbl layout differs from the PDB");
