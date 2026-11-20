// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TES; size 0x2c0
#pragma once

#include "BSSimpleList_RE__BSTTuple_RE__TESNPC_unsigned_short_344d88eb.h"
#include "BSSimpleList_RE__NiPointer_RE__ImageSpaceModifierInstance_c30f8b04.h"
#include "BSTEventSink_RE__BSResource__ArchiveStreamOpenedEvent_6f31c7a9.h"
#include "BSTEventSink_RE__PositionPlayerEvent_141ac998.h"
#include "ICellAttachDetachEventSource.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
#include "SystemEventAdapter.h"
struct BSTempNodeManager;
struct GridCellArray;
struct LoadedAreaBound;
struct NavMeshInfoMap;
struct NiDirectionalLight;
struct NiFogProperty;
struct NiNode;
struct PlayerCharacter;
struct QueuedFile_8dc5a4cb;
struct Sky;
struct TESObjectCELL_f81013b3;
struct TESWorldSpace;
struct TES {
    ICellAttachDetachEventSource _base;
    BSTEventSink_RE__BSResource__ArchiveStreamOpenedEvent_6f31c7a9 _base_BSTEventSink_RE_BSResource_ArchiveStreamOpenedEvent_;
    BSTEventSink_RE__PositionPlayerEvent_141ac998 _base_BSTEventSink_RE_PositionPlayerEvent_;
    unsigned long long unk070;
    GridCellArray* gridCells;
    NiNode* objRoot;
    NiNode* lodLandRoot;
    NiNode* objLODWaterRoot;
    BSTempNodeManager* tempNodeManager;
    NiDirectionalLight* objLight;
    NiFogProperty* objFog;
    int currentGridX;
    int currentGridY;
    int currentQueuedX;
    int currentQueuedY;
    TESObjectCELL_f81013b3* interiorCell;
    TESObjectCELL_f81013b3** interiorBuffer;
    TESObjectCELL_f81013b3** exteriorBuffer;
    unsigned long long unk0D8;
    int saveGridX;
    int saveGridY;
    unsigned long long unk0E8;
    unsigned long long unk0F0;
    unsigned long long unk0F8;
    Sky* sky;
    BSSimpleList_RE__NiPointer_RE__ImageSpaceModifierInstance_c30f8b04 activeImageSpaceModifiers;
    unsigned long long unk118;
    unsigned long long unk120;
    unsigned int unk128;
    unsigned int landBorderMode;
    unsigned int borderColorAGBR;
    float gridBufferDistanceX;
    float gridBufferDistanceY;
    bool allowUnusedPurge;
    unsigned char pad13D[3];
    unsigned long long unk140;
    TESWorldSpace* worldSpace;
    BSSimpleList_RE__BSTTuple_RE__TESNPC_unsigned_short_344d88eb deadCount;
    QueuedFile_8dc5a4cb* queuedFaceGenAddonHandle;
    NiPointer_RE__NiSourceTexture_cf356212 bloodDecalTexture;
    QueuedFile_8dc5a4cb* queuedFormDataHandle;
    QueuedFile_8dc5a4cb* queuedBloodSprayWaterSplashHandle;
    unsigned long long unk178;
    unsigned long long unk180;
    unsigned long long unk188;
    unsigned long long unk190;
    unsigned long long unk198;
    unsigned long long unk1A0;
    unsigned long long unk1A8;
    unsigned long long unk1B0;
    unsigned long long unk1B8;
    unsigned long long unk1C0;
    unsigned long long unk1C8;
    unsigned long long unk1D0;
    unsigned long long unk1D8;
    unsigned long long unk1E0;
    unsigned long long unk1E8;
    unsigned long long unk1F0;
    unsigned long long unk1F8;
    unsigned long long unk200;
    unsigned long long unk208;
    unsigned long long unk210;
    unsigned long long unk218;
    unsigned long long unk220;
    PlayerCharacter* playerCharacter;
    unsigned long long unk230;
    unsigned long long unk238;
    unsigned long long unk240;
    unsigned long long unk248;
    unsigned long long unk250;
    unsigned long long unk258;
    unsigned long long unk260;
    unsigned long long unk268;
    unsigned long long unk270;
    unsigned long long unk278;
    unsigned long long unk280;
    void* unk288;
    SystemEventAdapter unk290;
    unsigned long long unk2A0;
    NavMeshInfoMap* unk2A8;
    LoadedAreaBound* loadedAreaBound;
};
static_assert(sizeof(TES) == 704, "TES layout differs from the PDB");
