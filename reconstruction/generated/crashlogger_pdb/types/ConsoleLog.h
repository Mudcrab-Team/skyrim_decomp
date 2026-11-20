// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ConsoleLog; size 0x418
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTSingletonSDM_RE__ConsoleLog_2a86dfe4.h"
struct ConsoleLog {
    BSTSingletonSDM_RE__ConsoleLog_2a86dfe4 _base;
    unsigned char lastMessage[1024];
    unsigned char pad401;
    unsigned short pad402;
    unsigned int pad404;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce buffer;
};
static_assert(sizeof(ConsoleLog) == 1048, "ConsoleLog layout differs from the PDB");
