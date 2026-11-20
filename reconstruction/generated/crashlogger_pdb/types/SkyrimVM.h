// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SkyrimVM; size 0x8988
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__BSTSmartPointer_RE__SkyrimVM__LOSDataEvent_72cd484e.h"
#include "BSTArray_RE__BSTSmartPointer_RE__SkyrimVM__UpdateDataEvent_c6866b98.h"
#include "BSTArray_RE__SkyrimVM__WaitCall_cbddaab1.h"
#include "BSTEventSink_RE__BSScript__StatsEvent_2ab41112.h"
#include "BSTEventSink_RE__PositionPlayerEvent_141ac998.h"
#include "BSTEventSink_RE__TESActivateEvent_1ee36aab.h"
#include "BSTEventSink_RE__TESActiveEffectApplyRemoveEvent_f99a3ae0.h"
#include "BSTEventSink_RE__TESActorLocationChangeEvent_adefccb6.h"
#include "BSTEventSink_RE__TESBookReadEvent_1960fe9c.h"
#include "BSTEventSink_RE__TESCellAttachDetachEvent_09d6d32d.h"
#include "BSTEventSink_RE__TESCellFullyLoadedEvent_8bc292e7.h"
#include "BSTEventSink_RE__TESCombatEvent_14caccae.h"
#include "BSTEventSink_RE__TESContainerChangedEvent_8fcc8799.h"
#include "BSTEventSink_RE__TESDeathEvent_7bd18c51.h"
#include "BSTEventSink_RE__TESDestructionStageChangedEvent_3729d230.h"
#include "BSTEventSink_RE__TESEnterBleedoutEvent_5cf695ab.h"
#include "BSTEventSink_RE__TESEquipEvent_bb480b56.h"
#include "BSTEventSink_RE__TESFastTravelEndEvent_fc1395ee.h"
#include "BSTEventSink_RE__TESFormDeleteEvent_5ff3aeaa.h"
#include "BSTEventSink_RE__TESFurnitureEvent_367f773e.h"
#include "BSTEventSink_RE__TESGrabReleaseEvent_78408cbc.h"
#include "BSTEventSink_RE__TESHitEvent_ebba9de3.h"
#include "BSTEventSink_RE__TESInitScriptEvent_58b506ee.h"
#include "BSTEventSink_RE__TESLoadGameEvent_8c26bbb3.h"
#include "BSTEventSink_RE__TESLockChangedEvent_4d94236a.h"
#include "BSTEventSink_RE__TESMagicEffectApplyEvent_565bd3f8.h"
#include "BSTEventSink_RE__TESMagicWardHitEvent_fafa2ef8.h"
#include "BSTEventSink_RE__TESMoveAttachDetachEvent_243241ea.h"
#include "BSTEventSink_RE__TESObjectLoadedEvent_ac688fa9.h"
#include "BSTEventSink_RE__TESObjectREFRTranslationEvent_b1042396.h"
#include "BSTEventSink_RE__TESOpenCloseEvent_4db1e5f6.h"
#include "BSTEventSink_RE__TESPackageEvent_ecfe28fa.h"
#include "BSTEventSink_RE__TESPerkEntryRunEvent_b6f36ab4.h"
#include "BSTEventSink_RE__TESPlayerBowShotEvent_dd137cdd.h"
#include "BSTEventSink_RE__TESQuestInitEvent_0fc81304.h"
#include "BSTEventSink_RE__TESQuestStageEvent_f14e7791.h"
#include "BSTEventSink_RE__TESResetEvent_42ff8159.h"
#include "BSTEventSink_RE__TESResolveNPCTemplatesEvent_5873047d.h"
#include "BSTEventSink_RE__TESSceneActionEvent_afd38dad.h"
#include "BSTEventSink_RE__TESSceneEvent_cd7b43f5.h"
#include "BSTEventSink_RE__TESScenePhaseEvent_0c442099.h"
#include "BSTEventSink_RE__TESSellEvent_42ae1476.h"
#include "BSTEventSink_RE__TESSleepStartEvent_35774a14.h"
#include "BSTEventSink_RE__TESSleepStopEvent_71acf051.h"
#include "BSTEventSink_RE__TESSpellCastEvent_0f2dea31.h"
#include "BSTEventSink_RE__TESSwitchRaceCompleteEvent_8e69b932.h"
#include "BSTEventSink_RE__TESTopicInfoEvent_1edc2736.h"
#include "BSTEventSink_RE__TESTrackedStatsEvent_8b2284e2.h"
#include "BSTEventSink_RE__TESTrapHitEvent_f9790474.h"
#include "BSTEventSink_RE__TESTriggerEnterEvent_355139c1.h"
#include "BSTEventSink_RE__TESTriggerEvent_38abf19e.h"
#include "BSTEventSink_RE__TESTriggerLeaveEvent_e6d9935f.h"
#include "BSTEventSink_RE__TESUniqueIDChangeEvent_9869192e.h"
#include "BSTEventSource_RE__BSScript__StatsEvent_0258e4ce.h"
#include "BSTSingletonSDM_RE__SkyrimVM_eaf33ee3.h"
#include "BSTSmartPointer_RE__BSScript__IVirtualMachine_61b41a23.h"
#include "BSTSmartPointer_RE__SkyrimScript__Store_8c9406a5.h"
#include "IFreezeQuery.h"
#include "IStackCallbackSaveInterface.h"
struct SkyrimVM {
    IFreezeQuery _base;
    IStackCallbackSaveInterface _base_IStackCallbackSaveInterface;
    BSTEventSink_RE__TESActivateEvent_1ee36aab _base_BSTEventSink_RE_TESActivateEvent_;
    BSTEventSink_RE__TESActiveEffectApplyRemoveEvent_f99a3ae0 _base_BSTEventSink_RE_TESActiveEffectApplyRemoveEvent_;
    BSTEventSink_RE__TESActorLocationChangeEvent_adefccb6 _base_BSTEventSink_RE_TESActorLocationChangeEvent_;
    BSTEventSink_RE__TESBookReadEvent_1960fe9c _base_BSTEventSink_RE_TESBookReadEvent_;
    BSTEventSink_RE__TESCellAttachDetachEvent_09d6d32d _base_BSTEventSink_RE_TESCellAttachDetachEvent_;
    BSTEventSink_RE__TESCellFullyLoadedEvent_8bc292e7 _base_BSTEventSink_RE_TESCellFullyLoadedEvent_;
    BSTEventSink_RE__TESCombatEvent_14caccae _base_BSTEventSink_RE_TESCombatEvent_;
    BSTEventSink_RE__TESContainerChangedEvent_8fcc8799 _base_BSTEventSink_RE_TESContainerChangedEvent_;
    BSTEventSink_RE__TESDeathEvent_7bd18c51 _base_BSTEventSink_RE_TESDeathEvent_;
    BSTEventSink_RE__TESDestructionStageChangedEvent_3729d230 _base_BSTEventSink_RE_TESDestructionStageChangedEvent_;
    BSTEventSink_RE__TESEnterBleedoutEvent_5cf695ab _base_BSTEventSink_RE_TESEnterBleedoutEvent_;
    BSTEventSink_RE__TESEquipEvent_bb480b56 _base_BSTEventSink_RE_TESEquipEvent_;
    BSTEventSink_RE__TESFormDeleteEvent_5ff3aeaa _base_BSTEventSink_RE_TESFormDeleteEvent_;
    BSTEventSink_RE__TESFurnitureEvent_367f773e _base_BSTEventSink_RE_TESFurnitureEvent_;
    BSTEventSink_RE__TESGrabReleaseEvent_78408cbc _base_BSTEventSink_RE_TESGrabReleaseEvent_;
    BSTEventSink_RE__TESHitEvent_ebba9de3 _base_BSTEventSink_RE_TESHitEvent_;
    BSTEventSink_RE__TESInitScriptEvent_58b506ee _base_BSTEventSink_RE_TESInitScriptEvent_;
    BSTEventSink_RE__TESLoadGameEvent_8c26bbb3 _base_BSTEventSink_RE_TESLoadGameEvent_;
    BSTEventSink_RE__TESLockChangedEvent_4d94236a _base_BSTEventSink_RE_TESLockChangedEvent_;
    BSTEventSink_RE__TESMagicEffectApplyEvent_565bd3f8 _base_BSTEventSink_RE_TESMagicEffectApplyEvent_;
    BSTEventSink_RE__TESMagicWardHitEvent_fafa2ef8 _base_BSTEventSink_RE_TESMagicWardHitEvent_;
    BSTEventSink_RE__TESMoveAttachDetachEvent_243241ea _base_BSTEventSink_RE_TESMoveAttachDetachEvent_;
    BSTEventSink_RE__TESObjectLoadedEvent_ac688fa9 _base_BSTEventSink_RE_TESObjectLoadedEvent_;
    BSTEventSink_RE__TESObjectREFRTranslationEvent_b1042396 _base_BSTEventSink_RE_TESObjectREFRTranslationEvent_;
    BSTEventSink_RE__TESOpenCloseEvent_4db1e5f6 _base_BSTEventSink_RE_TESOpenCloseEvent_;
    BSTEventSink_RE__TESPackageEvent_ecfe28fa _base_BSTEventSink_RE_TESPackageEvent_;
    BSTEventSink_RE__TESPerkEntryRunEvent_b6f36ab4 _base_BSTEventSink_RE_TESPerkEntryRunEvent_;
    BSTEventSink_RE__TESQuestInitEvent_0fc81304 _base_BSTEventSink_RE_TESQuestInitEvent_;
    BSTEventSink_RE__TESQuestStageEvent_f14e7791 _base_BSTEventSink_RE_TESQuestStageEvent_;
    BSTEventSink_RE__TESResetEvent_42ff8159 _base_BSTEventSink_RE_TESResetEvent_;
    BSTEventSink_RE__TESResolveNPCTemplatesEvent_5873047d _base_BSTEventSink_RE_TESResolveNPCTemplatesEvent_;
    BSTEventSink_RE__TESSceneEvent_cd7b43f5 _base_BSTEventSink_RE_TESSceneEvent_;
    BSTEventSink_RE__TESSceneActionEvent_afd38dad _base_BSTEventSink_RE_TESSceneActionEvent_;
    BSTEventSink_RE__TESScenePhaseEvent_0c442099 _base_BSTEventSink_RE_TESScenePhaseEvent_;
    BSTEventSink_RE__TESSellEvent_42ae1476 _base_BSTEventSink_RE_TESSellEvent_;
    BSTEventSink_RE__TESSleepStartEvent_35774a14 _base_BSTEventSink_RE_TESSleepStartEvent_;
    BSTEventSink_RE__TESSleepStopEvent_71acf051 _base_BSTEventSink_RE_TESSleepStopEvent_;
    BSTEventSink_RE__TESSpellCastEvent_0f2dea31 _base_BSTEventSink_RE_TESSpellCastEvent_;
    BSTEventSink_RE__TESTopicInfoEvent_1edc2736 _base_BSTEventSink_RE_TESTopicInfoEvent_;
    BSTEventSink_RE__TESTrackedStatsEvent_8b2284e2 _base_BSTEventSink_RE_TESTrackedStatsEvent_;
    BSTEventSink_RE__TESTrapHitEvent_f9790474 _base_BSTEventSink_RE_TESTrapHitEvent_;
    BSTEventSink_RE__TESTriggerEvent_38abf19e _base_BSTEventSink_RE_TESTriggerEvent_;
    BSTEventSink_RE__TESTriggerEnterEvent_355139c1 _base_BSTEventSink_RE_TESTriggerEnterEvent_;
    BSTEventSink_RE__TESTriggerLeaveEvent_e6d9935f _base_BSTEventSink_RE_TESTriggerLeaveEvent_;
    BSTEventSink_RE__TESUniqueIDChangeEvent_9869192e _base_BSTEventSink_RE_TESUniqueIDChangeEvent_;
    BSTEventSink_RE__TESSwitchRaceCompleteEvent_8e69b932 _base_BSTEventSink_RE_TESSwitchRaceCompleteEvent_;
    BSTEventSink_RE__TESPlayerBowShotEvent_dd137cdd _base_BSTEventSink_RE_TESPlayerBowShotEvent_;
    BSTEventSink_RE__TESFastTravelEndEvent_fc1395ee _base_BSTEventSink_RE_TESFastTravelEndEvent_;
    BSTEventSink_RE__PositionPlayerEvent_141ac998 _base_BSTEventSink_RE_PositionPlayerEvent_;
    BSTEventSink_RE__BSScript__StatsEvent_2ab41112 _base_BSTEventSink_RE_BSScript_StatsEvent_;
    BSTSingletonSDM_RE__SkyrimVM_eaf33ee3 _base_BSTSingletonSDM_RE_SkyrimVM_;
    unsigned char undefined_1a1[7];
    BSTEventSource_RE__BSScript__StatsEvent_0258e4ce _base_BSTEventSource_RE_BSScript_StatsEvent_;
    unsigned char undefined_200[16];
    BSTSmartPointer_RE__BSScript__IVirtualMachine_61b41a23 impl;
    unsigned char saveLoadInterface[8];
    unsigned char debugInterface[8];
    unsigned char memoryPagePolicy[40];
    unsigned char scriptLoader[56];
    unsigned char logger[176];
    unsigned char handlePolicy[112];
    unsigned char objectBindPolicy[216];
    BSTSmartPointer_RE__SkyrimScript__Store_8c9406a5 scriptStore;
    unsigned char fragmentSystem[280];
    unsigned char profiler[224];
    unsigned char savePatcher[8];
    BSSpinLock frozenLock;
    unsigned int isFrozen;
    BSSpinLock currentVMTimeLock;
    unsigned int currentVMTime;
    unsigned int currentVMMenuModeTime;
    unsigned int currentVMGameTime;
    unsigned int currentVMDaysPassed;
    BSSpinLock queuedWaitEventLock;
    unsigned char undefined_6b4[4];
    BSTArray_RE__SkyrimVM__WaitCall_cbddaab1 queuedWaitCalls;
    BSTArray_RE__SkyrimVM__WaitCall_cbddaab1 queuedWaitMenuModeCalls;
    BSTArray_RE__SkyrimVM__WaitCall_cbddaab1 queuedWaitGameCalls;
    BSSpinLock queuedLOSEventCheckLock;
    BSTArray_RE__BSTSmartPointer_RE__SkyrimVM__LOSDataEvent_72cd484e queuedLOSEventChecks;
    unsigned int currentLOSEventCheckIndex;
    BSSpinLock queuedOnUpdateEventLock;
    unsigned char undefined_72c[4];
    BSTArray_RE__BSTSmartPointer_RE__SkyrimVM__UpdateDataEvent_c6866b98 queuedOnUpdateEvents;
    BSTArray_RE__BSTSmartPointer_RE__SkyrimVM__UpdateDataEvent_c6866b98 queuedOnUpdateGameEvents;
    unsigned int unk0750;
    BSSpinLock registeredSleepEventsLock;
    unsigned int pad076C;
    unsigned char undefined_770[33304];
};
static_assert(sizeof(SkyrimVM) == 35208, "SkyrimVM layout differs from the PDB");
