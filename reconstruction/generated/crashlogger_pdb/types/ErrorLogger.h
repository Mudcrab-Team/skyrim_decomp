// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ErrorLogger; size 0x98
#pragma once

#include "BSSpinLock.h"
#include "BSTEventSource_RE__BSScript__LogEvent_270aa805.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_cc7f3d3d.h"
struct ErrorLogger_vtbl;
struct ErrorLogger {
    ErrorLogger_vtbl* __vftable;
    BSTEventSource_RE__BSScript__LogEvent_270aa805 _base_BSTEventSource_RE_BSScript_LogEvent_;
    BSSpinLock threadErrorsLock;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_cc7f3d3d threadErrors;
};
static_assert(sizeof(ErrorLogger) == 152, "ErrorLogger layout differs from the PDB");
