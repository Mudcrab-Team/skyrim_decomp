// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MistMenu; size 0x140
#pragma once

#include "IMenu_09c1ffe2.h"
#include "MenuEventHandler.h"
#include "NiMatrix3.h"
#include "NiPointer_RE__BSFadeNode_1964a43a.h"
#include "NiPointer_RE__NiControllerManager_5b326bd5.h"
#include "NiPointer_RE__NiControllerSequence_87fc1ea3.h"
#include "NiPointer_RE__NiNode_28171d5b.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
#include "SimpleAnimationGraphManagerHolder.h"
struct BSLightingShaderProperty_d06e568e;
struct ImageSpaceBaseData;
struct MistMenu {
    IMenu_09c1ffe2 _base;
    SimpleAnimationGraphManagerHolder _base_SimpleAnimationGraphManagerHolder;
    MenuEventHandler _base_MenuEventHandler;
    unsigned char ambientColors_raw[72];
    unsigned int unk0A0;
    unsigned int unk0A4;
    unsigned long long unk0A8;
    NiPointer_RE__NiNode_28171d5b mistModel;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 mistModelDBHandle;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 loadScreenModelHandle;
    NiPointer_RE__BSFadeNode_1964a43a cameraPath;
    NiPointer_RE__NiNode_28171d5b cameraPathNode;
    NiPointer_RE__NiControllerSequence_87fc1ea3 cameraPathSequence;
    NiPointer_RE__NiControllerManager_5b326bd5 cameraPathController;
    BSLightingShaderProperty_d06e568e* logoShaderProperty;
    NiPointer_RE__BSFadeNode_1964a43a loadScreenModel;
    ImageSpaceBaseData* originalImageSpace;
    float cameraFOV;
    float angleZ;
    float unk108;
    float unk10C;
    NiMatrix3 cameraRotate;
    bool showMist;
    bool showLoadScreen;
    unsigned char unk136;
    unsigned char unk137;
    unsigned char unk138;
    unsigned char unk139;
    bool leftButtonHeldDown;
    bool rightButtonHeldDown;
    unsigned int pad13C;
};
static_assert(sizeof(MistMenu) == 320, "MistMenu layout differs from the PDB");
