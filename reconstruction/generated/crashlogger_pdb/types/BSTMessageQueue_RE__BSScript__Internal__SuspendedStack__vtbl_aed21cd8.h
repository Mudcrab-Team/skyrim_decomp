// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTMessageQueue<RE::BSScript::Internal::SuspendedStack>_vtbl; size 0x28
#pragma once
struct BSTMessageQueue_RE__BSScript__Internal__SuspendedStack__vtbl_aed21cd8 {
    void (*_dtor_BSTMessageQueue)(void);
    void (*Push)(void);
    bool (*TryPush)(void** );
    void (*Pop)(void);
    bool (*TryPop)(void** );
};
static_assert(sizeof(BSTMessageQueue_RE__BSScript__Internal__SuspendedStack__vtbl_aed21cd8) == 40, "BSTMessageQueue_RE__BSScript__Internal__SuspendedStack__vtbl_aed21cd8 layout differs from the PDB");
