// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GLock; size 0x28
#pragma once

#include "CRITICAL_SECTION_9c93bfc5.h"
struct GLock {
    CRITICAL_SECTION_9c93bfc5 cs;
};
static_assert(sizeof(GLock) == 40, "GLock layout differs from the PDB");
