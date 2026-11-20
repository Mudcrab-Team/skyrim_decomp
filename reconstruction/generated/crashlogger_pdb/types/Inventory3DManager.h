// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Inventory3DManager; size 0x168
#pragma once

#include "BSTSingletonSDM_RE__Inventory3DManager_b2d779a5.h"
#include "ExtraDataList.h"
#include "INTERFACE_LIGHT_SCHEME.h"
#include "MenuEventHandler.h"
#include "NiPoint3.h"
struct TESObjectREFR_b225f218;
struct Inventory3DManager {
    MenuEventHandler _base;
    BSTSingletonSDM_RE__Inventory3DManager_b2d779a5 _base_BSTSingletonSDM_RE_Inventory3DManager_;
    unsigned char unk011;
    unsigned short unk012;
    NiPoint3 itemPosCopy;
    NiPoint3 itemPos;
    float itemScaleCopy;
    float itemScale;
    INTERFACE_LIGHT_SCHEME currentLightScheme;
    TESObjectREFR_b225f218* tempRef;
    ExtraDataList originalExtra;
    unsigned char undefined_60[232];
    unsigned int loadedModelCount;
    unsigned char undefined_14c[4];
    float zoomDistance;
    float zoomProgress;
    char32_t* loadTask;
    bool enableUserInput;
    unsigned char unk161;
    bool startedZoom;
    unsigned char pad163[1];
    unsigned int pad164;
};
static_assert(sizeof(Inventory3DManager) == 360, "Inventory3DManager layout differs from the PDB");
