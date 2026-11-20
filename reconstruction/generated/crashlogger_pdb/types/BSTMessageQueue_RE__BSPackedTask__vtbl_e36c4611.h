// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTMessageQueue<RE::BSPackedTask>_vtbl; size 0x28
#pragma once
struct BSTMessageQueue_RE__BSPackedTask__vtbl_e36c4611 {
    void (*_dtor_BSTMessageQueue)(void);
    void (*Push)(void);
    bool (*TryPush)(void** );
    void (*Pop)(void);
    bool (*TryPop)(void** );
};
static_assert(sizeof(BSTMessageQueue_RE__BSPackedTask__vtbl_e36c4611) == 40, "BSTMessageQueue_RE__BSPackedTask__vtbl_e36c4611 layout differs from the PDB");
