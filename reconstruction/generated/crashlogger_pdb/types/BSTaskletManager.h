// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTaskletManager; size 0x20
#pragma once

struct BSTaskletManager_vtbl;
struct BSTaskletManager {
    BSTaskletManager_vtbl* __vftable;
    bool canCreateTaskGroup;
    bool started;
    unsigned char pad0A[6];
    void* instanceSemaphore;
    int instanceCount;
    unsigned int unk1C;
};
static_assert(sizeof(BSTaskletManager) == 32, "BSTaskletManager layout differs from the PDB");
