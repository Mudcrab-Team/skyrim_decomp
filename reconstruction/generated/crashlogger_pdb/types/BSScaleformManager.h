// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSScaleformManager; size 0x40
#pragma once

#include "BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce.h"
#include "BSTSingletonSDM_RE__BSScaleformManager_21264bd4.h"
#include "GPtr_RE__BSScaleformImageLoader_5e880d59.h"
#include "GPtr_RE__GFxDrawTextManager_3cccf39e.h"
struct BSScaleformRenderer;
struct BSScaleformTranslator;
struct GFxLoader;
struct BSScaleformManager {
    BSTSingletonSDM_RE__BSScaleformManager_21264bd4 _base;
    unsigned char pad01;
    unsigned short pad02;
    unsigned int pad04;
    GFxLoader* loader;
    BSScaleformRenderer* renderer;
    GPtr_RE__GFxDrawTextManager_3cccf39e textManager;
    GPtr_RE__BSScaleformImageLoader_5e880d59 imageLoader;
    BSStringT_char_4294967295_RE__DynamicMemoryManagementPol_806a78ce validNameChars;
    BSScaleformTranslator* translator;
};
static_assert(sizeof(BSScaleformManager) == 64, "BSScaleformManager layout differs from the PDB");
