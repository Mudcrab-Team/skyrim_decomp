// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LoadNIFData; size 0x50
#pragma once

#include "TESModel_c52655e4.h"
struct TESBoundObject_fc790793;
struct LoadNIFData {
    TESBoundObject_fc790793* loadNIF;
    float initialScale;
    short rotationConstraints[3];
    short rotationOffsetConstraints[2];
    unsigned short pad16;
    float initialTranslationOffset[3];
    unsigned int pad24;
    TESModel_c52655e4 cameraPath;
};
static_assert(sizeof(LoadNIFData) == 80, "LoadNIFData layout differs from the PDB");
