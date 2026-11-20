// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GFxImportNode; size 0x30
#pragma once

#include "GArray_RE__GFxImportNode__ImportAssetInfo_9da92a1a.h"
#include "GString.h"
struct GFxImportNode {
    GArray_RE__GFxImportNode__ImportAssetInfo_9da92a1a assets;
    GString filename;
    unsigned int frame;
    unsigned int movieIndex;
    GFxImportNode* nextInChain;
};
static_assert(sizeof(GFxImportNode) == 48, "GFxImportNode layout differs from the PDB");
