// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletGroupData; size 0x50
#pragma once

#include "CRITICAL_SECTION_9c93bfc5.h"
struct BSTaskletGroupData_vtbl;
struct BSTaskletGroupData {
    BSTaskletGroupData_vtbl* __vftable;
    bool allComplete;
    unsigned char pad09[7];
    void* completionSemaphore;
    CRITICAL_SECTION_9c93bfc5 lock;
    bool unk40;
    bool unk41;
    bool cancelled;
    unsigned char unk43;
    unsigned int unk44;
    int totalTaskCount;
    int completedTaskCount;
};
static_assert(sizeof(BSTaskletGroupData) == 80, "BSTaskletGroupData layout differs from the PDB");
