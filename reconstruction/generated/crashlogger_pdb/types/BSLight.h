// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLight; size 0x140
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BSMultiBoundRoom_42957b6c.h"
#include "BSTArray_RE__BSPortalSharedNode_60ede45b_d46b78cc.h"
#include "BSTArray_RE__BSPortal_c410012f_69b7877c.h"
#include "NiPoint3_a7124070.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiLight_e90f0c52.h"
#include "NiRefObject.h"
struct BSCullingProcess;
struct BSLensFlareRenderData_ff929930;
struct BSPortalGraph_399cc2f4;
struct RE__NiTListItem_RE__NiPointer_RE__BSTriShape_24c42ca9;
struct BSLight {
    NiRefObject _base;
    float luminance;
    float lodDimmer;
    unsigned char geomList_raw[32];
    unsigned long long unk038;
    unsigned int unk040;
    bool pointLight;
    bool ambientLight;
    bool dynamic;
    bool portalStrict;
    NiPointer_RE__NiLight_e90f0c52 light;
    NiPoint3_a7124070 worldTranslate;
    unsigned int frustrumCull;
    unsigned char unk060;
    bool affectLand;
    bool affectWater;
    bool lodFade;
    unsigned int unk064;
    RE__NiTListItem_RE__NiPointer_RE__BSTriShape_24c42ca9* geomListFence;
    unsigned char unk070[96];
    unsigned char unk0D0;
    unsigned char pad0D1;
    unsigned short pad0D2;
    unsigned int pad0D4;
    BSTArray_RE__BSMultiBoundRoom_42957b6c rooms;
    BSTArray_RE__BSPortal_c410012f_69b7877c portals;
    BSTArray_RE__BSPortalSharedNode_60ede45b_d46b78cc portalSharedNodes;
    BSPortalGraph_399cc2f4* portalGraph;
    BSCullingProcess* cullingProcess;
    NiPointer_RE__NiAVObject_9e3aa701 objectNode;
    BSLensFlareRenderData_ff929930* lensFlareData;
};
static_assert(sizeof(BSLight) == 320, "BSLight layout differs from the PDB");
