// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ObjectBindPolicy; size 0x50
#pragma once

#include "BSSpinLock.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860.h"
struct IVMObjectBindInterface;
struct IVirtualMachine;
struct ObjectBindPolicy_vtbl;
struct ObjectBindPolicy {
    ObjectBindPolicy_vtbl* __vftable;
    IVirtualMachine* vm;
    IVMObjectBindInterface* bindInterface;
    BSSpinLock attachedScriptsLock;
    BSTScatterTable_RE__BSCRC32_unsigned_long_long_std__equal_to_unsigned_long_long_RE__BST_7fe24860 attachedScripts;
};
static_assert(sizeof(ObjectBindPolicy) == 80, "ObjectBindPolicy layout differs from the PDB");
