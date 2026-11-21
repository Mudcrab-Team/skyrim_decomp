// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: IMemoryPagePolicy_vtbl; size 0x28
#pragma once

#include "AllocationStatus.h"
#include "NewPageStrategy.h"
struct IMemoryPagePolicy_vtbl {
    void (*_dtor_IMemoryPagePolicy)(void);
    unsigned int (*MaximumPageSize)(void);
    AllocationStatus (*AllocatePage)(unsigned int, NewPageStrategy, char32_t* );
    AllocationStatus (*GetLargestAvailablePage)(char32_t* );
    void (*DisposePage)(char32_t* );
};
static_assert(sizeof(IMemoryPagePolicy_vtbl) == 40, "IMemoryPagePolicy_vtbl layout differs from the PDB");
