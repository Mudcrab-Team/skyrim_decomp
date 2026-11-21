// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ImportAssetInfo; size 0x10
#pragma once

#include "GString.h"
struct ImportAssetInfo {
    GString name;
    unsigned int id;
    unsigned int importIndex;
};
static_assert(sizeof(ImportAssetInfo) == 16, "ImportAssetInfo layout differs from the PDB");
