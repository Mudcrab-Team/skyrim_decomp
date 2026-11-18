// Source exposure: mixed (pinned community interface declarations and target RTTI/secondary-slot analysis).
// Code origin: adapted community interface declarations; original owner prefix and defaulted construction. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/I/IFreezeQuery.h, include/RE/I/IStackCallbackSaveInterface.h and include/RE/B/BSTEvent.h; MIT.
// IFreezeQuery, IStackCallbackSaveInterface, BSTEventSink, BSEventNotifyControl, GetIsFrozen, Unk_01, Unk_02, ProcessEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SkyrimVM: EXE_RTTI
// SkyrimVMInterfacePrefixLayout, SkyrimVMFreezeQueryLayout, SkyrimVMStackSaveLayout, SkyrimVMEventSinkLayout, SkyrimVMEventSourceLayout, SkyrimVMEventTag, SkyrimVMVptrPrefixStorageLayout: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
namespace ResearchLayouts {
enum class BSEventNotifyControl { kContinue = 0, kStop = 1 };
class SkyrimVMFreezeQueryLayout {
public:
    virtual ~SkyrimVMFreezeQueryLayout();
    virtual bool GetIsFrozen();
};
class SkyrimVMStackSaveLayout {
public:
    virtual ~SkyrimVMStackSaveLayout();
    virtual void Unk_01() = 0;
    virtual void Unk_02() = 0;
};
template<unsigned Index> class SkyrimVMEventTag;
template<class Event> class SkyrimVMEventSourceLayout;
template<class Event> class SkyrimVMEventSinkLayout {
public:
    virtual ~SkyrimVMEventSinkLayout() = default;
    virtual BSEventNotifyControl ProcessEvent(const Event*, SkyrimVMEventSourceLayout<Event>*) = 0;
};
static_assert(sizeof(SkyrimVMFreezeQueryLayout) == 8, "community fieldless freeze interface");
static_assert(sizeof(SkyrimVMStackSaveLayout) == 8, "community fieldless save interface");
static_assert(sizeof(SkyrimVMEventSinkLayout<void>) == 8, "community fieldless event sink");
// Prefix subobject 0, offset 0: .?AVIFreezeQuery@BSScript@@
// Prefix subobject 1, offset 8: .?AVIStackCallbackSaveInterface@BSScript@@
// Prefix subobject 2, offset 16: .?AV?$BSTEventSink@UTESActivateEvent@@@@
// Prefix subobject 3, offset 24: .?AV?$BSTEventSink@UTESActiveEffectApplyRemoveEvent@@@@
// Prefix subobject 4, offset 32: .?AV?$BSTEventSink@UTESActorLocationChangeEvent@@@@
// Prefix subobject 5, offset 40: .?AV?$BSTEventSink@UTESBookReadEvent@@@@
// Prefix subobject 6, offset 48: .?AV?$BSTEventSink@UTESCellAttachDetachEvent@@@@
// Prefix subobject 7, offset 56: .?AV?$BSTEventSink@UTESCellFullyLoadedEvent@@@@
// Prefix subobject 8, offset 64: .?AV?$BSTEventSink@UTESCombatEvent@@@@
// Prefix subobject 9, offset 72: .?AV?$BSTEventSink@UTESContainerChangedEvent@@@@
// Prefix subobject 10, offset 80: .?AV?$BSTEventSink@UTESDeathEvent@@@@
// Prefix subobject 11, offset 88: .?AV?$BSTEventSink@UTESDestructionStageChangedEvent@@@@
// Prefix subobject 12, offset 96: .?AV?$BSTEventSink@UTESEnterBleedoutEvent@@@@
// Prefix subobject 13, offset 104: .?AV?$BSTEventSink@UTESEquipEvent@@@@
// Prefix subobject 14, offset 112: .?AV?$BSTEventSink@UTESFormDeleteEvent@@@@
// Prefix subobject 15, offset 120: .?AV?$BSTEventSink@UTESFurnitureEvent@@@@
// Prefix subobject 16, offset 128: .?AV?$BSTEventSink@UTESGrabReleaseEvent@@@@
// Prefix subobject 17, offset 136: .?AV?$BSTEventSink@UTESHitEvent@@@@
// Prefix subobject 18, offset 144: .?AV?$BSTEventSink@UTESInitScriptEvent@@@@
// Prefix subobject 19, offset 152: .?AV?$BSTEventSink@UTESLoadGameEvent@@@@
// Prefix subobject 20, offset 160: .?AV?$BSTEventSink@UTESLockChangedEvent@@@@
// Prefix subobject 21, offset 168: .?AV?$BSTEventSink@UTESMagicEffectApplyEvent@@@@
// Prefix subobject 22, offset 176: .?AV?$BSTEventSink@UTESMagicWardHitEvent@@@@
// Prefix subobject 23, offset 184: .?AV?$BSTEventSink@UTESMoveAttachDetachEvent@@@@
// Prefix subobject 24, offset 192: .?AV?$BSTEventSink@UTESObjectLoadedEvent@@@@
// Prefix subobject 25, offset 200: .?AV?$BSTEventSink@UTESObjectREFRTranslationEvent@@@@
// Prefix subobject 26, offset 208: .?AV?$BSTEventSink@UTESOpenCloseEvent@@@@
// Prefix subobject 27, offset 216: .?AV?$BSTEventSink@UTESPackageEvent@@@@
// Prefix subobject 28, offset 224: .?AV?$BSTEventSink@UTESPerkEntryRunEvent@@@@
// Prefix subobject 29, offset 232: .?AV?$BSTEventSink@UTESQuestInitEvent@@@@
// Prefix subobject 30, offset 240: .?AV?$BSTEventSink@UTESQuestStageEvent@@@@
// Prefix subobject 31, offset 248: .?AV?$BSTEventSink@UTESResetEvent@@@@
// Prefix subobject 32, offset 256: .?AV?$BSTEventSink@UTESResolveNPCTemplatesEvent@@@@
// Prefix subobject 33, offset 264: .?AV?$BSTEventSink@UTESSceneEvent@@@@
// Prefix subobject 34, offset 272: .?AV?$BSTEventSink@UTESSceneActionEvent@@@@
// Prefix subobject 35, offset 280: .?AV?$BSTEventSink@UTESScenePhaseEvent@@@@
// Prefix subobject 36, offset 288: .?AV?$BSTEventSink@UTESSellEvent@@@@
// Prefix subobject 37, offset 296: .?AV?$BSTEventSink@UTESSleepStartEvent@@@@
// Prefix subobject 38, offset 304: .?AV?$BSTEventSink@UTESSleepStopEvent@@@@
// Prefix subobject 39, offset 312: .?AV?$BSTEventSink@UTESSpellCastEvent@@@@
// Prefix subobject 40, offset 320: .?AV?$BSTEventSink@UTESTopicInfoEvent@@@@
// Prefix subobject 41, offset 328: .?AV?$BSTEventSink@UTESTrackedStatsEvent@@@@
// Prefix subobject 42, offset 336: .?AV?$BSTEventSink@UTESTrapHitEvent@@@@
// Prefix subobject 43, offset 344: .?AV?$BSTEventSink@UTESTriggerEvent@@@@
// Prefix subobject 44, offset 352: .?AV?$BSTEventSink@UTESTriggerEnterEvent@@@@
// Prefix subobject 45, offset 360: .?AV?$BSTEventSink@UTESTriggerLeaveEvent@@@@
// Prefix subobject 46, offset 368: .?AV?$BSTEventSink@UTESUniqueIDChangeEvent@@@@
// Prefix subobject 47, offset 376: .?AV?$BSTEventSink@UTESSwitchRaceCompleteEvent@@@@
// Prefix subobject 48, offset 384: .?AV?$BSTEventSink@UTESAmiiboTouchEvent@@@@
// Prefix subobject 49, offset 392: .?AV?$BSTEventSink@UTESAmiiboForcedStopDetectionEvent@@@@
// Prefix subobject 50, offset 400: .?AV?$BSTEventSink@UTESPlayerBowShotEvent@@@@
// Prefix subobject 51, offset 408: .?AV?$BSTEventSink@UTESFastTravelEndEvent@@@@
// Prefix subobject 52, offset 416: .?AV?$BSTEventSink@UPositionPlayerEvent@@@@
// Prefix subobject 53, offset 424: .?AV?$BSTEventSink@UStatsEvent@BSScript@@@@
class SkyrimVMInterfacePrefixLayout :
    public SkyrimVMFreezeQueryLayout,
    public SkyrimVMStackSaveLayout,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<0>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<1>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<2>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<3>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<4>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<5>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<6>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<7>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<8>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<9>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<10>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<11>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<12>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<13>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<14>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<15>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<16>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<17>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<18>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<19>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<20>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<21>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<22>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<23>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<24>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<25>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<26>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<27>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<28>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<29>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<30>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<31>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<32>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<33>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<34>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<35>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<36>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<37>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<38>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<39>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<40>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<41>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<42>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<43>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<44>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<45>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<46>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<47>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<48>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<49>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<50>>,
    public SkyrimVMEventSinkLayout<SkyrimVMEventTag<51>> {
public:
    SkyrimVMInterfacePrefixLayout();
    ~SkyrimVMInterfacePrefixLayout() override;
};
static_assert(sizeof(SkyrimVMInterfacePrefixLayout) == 432, "complete polymorphic interface prefix only");
struct SkyrimVMVptrPrefixStorageLayout {
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
    const void* const* interface4;
    const void* const* interface5;
    const void* const* interface6;
    const void* const* interface7;
    const void* const* interface8;
    const void* const* interface9;
    const void* const* interface10;
    const void* const* interface11;
    const void* const* interface12;
    const void* const* interface13;
    const void* const* interface14;
    const void* const* interface15;
    const void* const* interface16;
    const void* const* interface17;
    const void* const* interface18;
    const void* const* interface19;
    const void* const* interface20;
    const void* const* interface21;
    const void* const* interface22;
    const void* const* interface23;
    const void* const* interface24;
    const void* const* interface25;
    const void* const* interface26;
    const void* const* interface27;
    const void* const* interface28;
    const void* const* interface29;
    const void* const* interface30;
    const void* const* interface31;
    const void* const* interface32;
    const void* const* interface33;
    const void* const* interface34;
    const void* const* interface35;
    const void* const* interface36;
    const void* const* interface37;
    const void* const* interface38;
    const void* const* interface39;
    const void* const* interface40;
    const void* const* interface41;
    const void* const* interface42;
    const void* const* interface43;
    const void* const* interface44;
    const void* const* interface45;
    const void* const* interface46;
    const void* const* interface47;
    const void* const* interface48;
    const void* const* interface49;
    const void* const* interface50;
    const void* const* interface51;
    const void* const* interface52;
    const void* const* interface53;
};
static_assert(sizeof(SkyrimVMVptrPrefixStorageLayout) == sizeof(SkyrimVMInterfacePrefixLayout), "physical vptr prefix mirror");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface0) == 0, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface1) == 8, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface2) == 16, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface3) == 24, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface4) == 32, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface5) == 40, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface6) == 48, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface7) == 56, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface8) == 64, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface9) == 72, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface10) == 80, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface11) == 88, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface12) == 96, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface13) == 104, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface14) == 112, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface15) == 120, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface16) == 128, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface17) == 136, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface18) == 144, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface19) == 152, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface20) == 160, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface21) == 168, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface22) == 176, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface23) == 184, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface24) == 192, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface25) == 200, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface26) == 208, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface27) == 216, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface28) == 224, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface29) == 232, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface30) == 240, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface31) == 248, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface32) == 256, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface33) == 264, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface34) == 272, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface35) == 280, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface36) == 288, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface37) == 296, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface38) == 304, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface39) == 312, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface40) == 320, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface41) == 328, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface42) == 336, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface43) == 344, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface44) == 352, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface45) == 360, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface46) == 368, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface47) == 376, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface48) == 384, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface49) == 392, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface50) == 400, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface51) == 408, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface52) == 416, "target RTTI subobject offset");
static_assert(offsetof(SkyrimVMVptrPrefixStorageLayout, interface53) == 424, "target RTTI subobject offset");
}
