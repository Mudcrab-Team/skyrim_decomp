// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: UI3DSceneManager; size 0x118
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__INTERFACE_LIGHT_SCHEME_23813226.h"
#include "BSTArray_RE__MenuLight_0391df77.h"
#include "BSTArray_RE__NiPointer_RE__TESImageSpaceModifier_fa00e6af.h"
#include "BSTSingletonSDM_RE__UI3DSceneManager_953598ac.h"
#include "INTERFACE_LIGHT_SCHEME.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
#include "NiPointer_RE__BSShaderAccumulator_c0b65593.h"
#include "NiPointer_RE__NiCamera_cf3a8333.h"
struct BSCullingProcess;
struct ShadowSceneNode;
struct UI3DSceneManager {
    BSTSingletonSDM_RE__UI3DSceneManager_953598ac _base;
    unsigned char pad01;
    unsigned short pad02;
    unsigned int pad04;
    BSCullingProcess* cullingProcess;
    NiPointer_RE__BSShaderAccumulator_c0b65593 unk10;
    NiPointer_RE__BSShaderAccumulator_c0b65593 unk18;
    NiPointer_RE__NiCamera_cf3a8333 camera;
    BSSpinLock lock;
    ShadowSceneNode* shadowSceneNode;
    unsigned char menuObjects_raw[64];
    BSTArray_RE__MenuLight_0391df77 menuLights;
    INTERFACE_LIGHT_SCHEME currentlightScheme;
    unsigned int pad94;
    BSTArray_RE__INTERFACE_LIGHT_SCHEME_23813226 lightSchemes;
    BSTArray_RE__NiPointer_RE__TESImageSpaceModifier_fa00e6af imageSpaceMods;
    NiPoint3 cachedCameraPos;
    NiMatrix3 cachedCameraRot;
    unsigned char viewFrustum_raw[32];
};
static_assert(sizeof(UI3DSceneManager) == 280, "UI3DSceneManager layout differs from the PDB");
