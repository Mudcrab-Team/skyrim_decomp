// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: LockpickingMenu; size 0x110
#pragma once

#include "BSSoundHandle.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "IMenu_09c1ffe2.h"
#include "MenuEventHandler.h"
#include "NiMatrix3.h"
#include "NiPoint3.h"
#include "RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265.h"
struct NiControllerManager;
struct NiControllerSequence_8a06e14d;
struct LockpickingMenu {
    IMenu_09c1ffe2 _base;
    MenuEventHandler _base_MenuEventHandler;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 lockpickShiv;
    RHandleType_RE__BSResource__Entry_RE__NiPointer_RE__NiNode_RE__BSResource__EntryDBTrait_03dfb265 pickModel;
    NiMatrix3 pickRotation;
    NiPoint3 lockRotCenter;
    NiControllerManager* lockController;
    NiControllerSequence_8a06e14d* lockIntro;
    NiControllerSequence_8a06e14d* lockRotate;
    NiControllerManager* pickController;
    NiControllerSequence_8a06e14d* pickIntro;
    NiControllerSequence_8a06e14d* pickDamage;
    NiControllerSequence_8a06e14d* pickBreak;
    NiControllerSequence_8a06e14d* currentPickSequence;
    float pickKeyTime;
    unsigned int unk0CC;
    NiControllerSequence_8a06e14d* currentLockSequence;
    float lockKeyTime;
    float pickAngle;
    float lockAngle;
    float damagePickAngle;
    float pickBreakSeconds;
    BSSoundHandle pickTensionSound;
    float unk0F8;
    float sweetSpotAngle;
    float partialPickAngle;
    unsigned int numBrokenPicks;
    bool init3DElements;
    bool animating;
    bool unk10A;
    bool menuCleared;
    bool animationFinished;
    bool isLockpickingCrime;
    unsigned char unk10E;
    unsigned char pad10F;
};
static_assert(sizeof(LockpickingMenu) == 272, "LockpickingMenu layout differs from the PDB");
