// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QueuedUnbindRefs; size 0x10
#pragma once

#include "BSTSmartPointer_RE__BSScript__Object_04f5caa3.h"
struct QueuedUnbindRefs {
    BSTSmartPointer_RE__BSScript__Object_04f5caa3 obj;
    unsigned int refCount;
    unsigned int pad0C;
};
static_assert(sizeof(QueuedUnbindRefs) == 16, "QueuedUnbindRefs layout differs from the PDB");
