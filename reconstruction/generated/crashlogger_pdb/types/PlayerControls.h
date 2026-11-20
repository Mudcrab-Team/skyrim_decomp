// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PlayerControls; size 0x1e0
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5.h"
#include "BSTArray_RE__HeldStateHandler_51a9b3d3.h"
#include "BSTArray_RE__PlayerInputHandler_93bb92c6.h"
#include "BSTArray_void_9eb8914c.h"
#include "BSTEventSink_RE__InputEvent_e78270ba.h"
#include "BSTEventSink_RE__MenuModeChangeEvent_37ac473d.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "BSTEventSink_RE__TESFurnitureEvent_367f773e.h"
#include "BSTSingletonSDM_RE__PlayerControls_57f9eb5d.h"
#include "PlayerControlsData.h"
struct ActivateHandler;
struct AttackBlockHandler;
struct AutoMoveHandler;
struct JumpHandler;
struct LookHandler;
struct MovementHandler;
struct ReadyWeaponHandler;
struct RunHandler;
struct ShoutHandler;
struct SneakHandler;
struct SprintHandler;
struct TogglePOVHandler;
struct ToggleRunHandler;
struct PlayerControls {
    BSTEventSink_RE__InputEvent_e78270ba _base;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    BSTEventSink_RE__MenuModeChangeEvent_37ac473d _base_BSTEventSink_RE_MenuModeChangeEvent_;
    BSTEventSink_RE__TESFurnitureEvent_367f773e _base_BSTEventSink_RE_TESFurnitureEvent_;
    BSTSingletonSDM_RE__PlayerControls_57f9eb5d _base_BSTSingletonSDM_RE_PlayerControls_;
    unsigned char pad021;
    unsigned short pad022;
    PlayerControlsData data;
    unsigned int pad054;
    BSTArray_RE__PlayerInputHandler_93bb92c6 handlers;
    BSTArray_RE__HeldStateHandler_51a9b3d3 heldStateHandlers;
    BSTArray_void_9eb8914c unk088;
    unsigned char unk0A0[8];
    unsigned long long unk0A8;
    float unk0B0[8];
    unsigned int unk0D0[10];
    unsigned char unk0F8[8];
    float unk100[20];
    BSTArray_RE__BSPointerHandle_RE__Actor_9929f3f1_3c6e0fb5 actionInterestedActor;
    BSSpinLock actorArrayLock;
    MovementHandler* movementHandler;
    LookHandler* lookHandler;
    SprintHandler* sprintHandler;
    ReadyWeaponHandler* readyWeaponHandler;
    AutoMoveHandler* autoMoveHandler;
    ToggleRunHandler* toggleRunHandler;
    ActivateHandler* activateHandler;
    JumpHandler* jumpHandler;
    ShoutHandler* shoutHandler;
    AttackBlockHandler* attackBlockHandler;
    RunHandler* runHandler;
    SneakHandler* sneakHandler;
    TogglePOVHandler* togglePOVHandler;
    bool notifyingHandlers;
    bool blockPlayerInput;
    unsigned short unk1DA;
    unsigned int unk1DC;
};
static_assert(sizeof(PlayerControls) == 480, "PlayerControls layout differs from the PDB");
