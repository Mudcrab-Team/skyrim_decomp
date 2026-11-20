// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MenuTopicManager; size 0xd8
#pragma once

#include "BSPointerHandle_RE__TESObjectREFR_017ae4a4.h"
#include "BSTArray_RE__BGSDialogueBranch_0424e2fb.h"
#include "BSTArray_RE__TESTopic_2a12dd2b.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "BSTEventSink_RE__PositionPlayerEvent_141ac998.h"
#include "BSTSingletonSDM_RE__MenuTopicManager_bc7fb984.h"
#include "CRITICAL_SECTION_9c93bfc5.h"
struct BSSimpleList_RE__BSSimpleList_RE__MenuTopicManager__Dialogue___Node_e4b4e0d9;
struct BSSimpleList_RE__MenuTopicManager__Dialogue_fdc784a1;
struct Dialogue;
struct Node_dfb14146;
struct TESTopicInfo_41161035;
struct MenuTopicManager {
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base;
    BSTEventSink_RE__PositionPlayerEvent_141ac998 _base_BSTEventSink_RE_PositionPlayerEvent_;
    BSTSingletonSDM_RE__MenuTopicManager_bc7fb984 _base_BSTSingletonSDM_RE_MenuTopicManager_;
    unsigned char undefined_11[7];
    Node_dfb14146* selectedResponseNode;
    BSSimpleList_RE__MenuTopicManager__Dialogue_fdc784a1* dialogueList;
    BSSimpleList_RE__BSSimpleList_RE__MenuTopicManager__Dialogue___Node_e4b4e0d9* dialogueListStack;
    TESTopicInfo_41161035* rootTopicInfo;
    Dialogue* lastSelectedDialogue;
    CRITICAL_SECTION_9c93bfc5 criticalSection;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 speaker;
    BSPointerHandle_RE__TESObjectREFR_017ae4a4 lastSpeaker;
    TESTopicInfo_41161035* currentTopicInfo;
    TESTopicInfo_41161035* lastTopicInfo;
    BSTArray_RE__BGSDialogueBranch_0424e2fb blockingBranches;
    BSTArray_RE__BGSDialogueBranch_0424e2fb topLevelBranches;
    bool isGreetingPlayer;
    bool menuOpen;
    bool forceGoodbye;
    bool shutMenu;
    bool rumorTopicAdded;
    bool waitingToAdvance;
    bool advanceRequested;
    bool skipHeadResponse;
    bool advanceInProgress;
    bool lineSkipped;
    bool canSkip;
    bool closeInProgress;
    unsigned short padBC;
    unsigned char undefined_be[2];
    BSTArray_RE__TESTopic_2a12dd2b topicHistory;
};
static_assert(sizeof(MenuTopicManager) == 216, "MenuTopicManager layout differs from the PDB");
