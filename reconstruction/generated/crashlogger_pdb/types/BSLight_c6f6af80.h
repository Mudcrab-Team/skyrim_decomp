// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLight; size 0x140
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BSMultiBoundRoom_42957b6c_f6437901.h"
#include "BSTArray_RE__BSPortalSharedNode_60ede45b.h"
#include "BSTArray_RE__BSPortal_c410012f.h"
#include "NiPoint3.h"
#include "NiPointer_RE__NiAVObject_9e3aa701.h"
#include "NiPointer_RE__NiLight_e90f0c52.h"
#include "NiRefObject_f24a9221.h"
#include "NodeListT_RE__NiPointer_RE__BSTriShape_907a6ef9.h"
struct BSCullingProcess;
struct BSLensFlareRenderData;
struct BSPortalGraph;
struct RE__NiTListItem_RE__NiPointer_RE__BSTriShape_24c42ca9;
struct BSLight_c6f6af80 {
    NiRefObject_f24a9221 _base;
    float luminance;
    float lodDimmer;
    NodeListT_RE__NiPointer_RE__BSTriShape_907a6ef9 geomList;
    unsigned long long unk038;
    unsigned int unk040;
    bool pointLight;
    bool ambientLight;
    bool dynamic;
    bool portalStrict;
    NiPointer_RE__NiLight_e90f0c52 light;
    NiPoint3 worldTranslate;
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
    BSTArray_RE__BSMultiBoundRoom_42957b6c_f6437901 rooms;
    BSTArray_RE__BSPortal_c410012f portals;
    BSTArray_RE__BSPortalSharedNode_60ede45b portalSharedNodes;
    BSPortalGraph* portalGraph;
    BSCullingProcess* cullingProcess;
    NiPointer_RE__NiAVObject_9e3aa701 objectNode;
    BSLensFlareRenderData* lensFlareData;
};
static_assert(sizeof(BSLight_c6f6af80) == 320, "BSLight_c6f6af80 layout differs from the PDB");
