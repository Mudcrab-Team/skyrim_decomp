// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSComputeShader; size 0x50
#pragma once

#include "BSReloadShaderI_ae70fb91.h"
#include "BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_94c2e8ce.h"
#include "NiRefObject_f24a9221.h"
struct BSComputeShader {
    NiRefObject_f24a9221 _base;
    BSReloadShaderI_ae70fb91 _base_BSReloadShaderI;
    unsigned char* name;
    BSTScatterTable_RE__BSCRC32_unsigned_int_std__equal_to_unsigned_int_RE__BSTScatterTable_94c2e8ce shadersMap;
};
static_assert(sizeof(BSComputeShader) == 80, "BSComputeShader layout differs from the PDB");
