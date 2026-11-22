// Source exposure: mixed (pinned public interface/reference/menu storage and independent target RTTI/slot analysis).
// Code origin: adapted community storage declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BSTEvent.h,B/BSIntrusiveRefCounted.h,G/GRefCountImpl.h,G/GFxFunctionHandler.h,F/FxDelegateHandler.h,J/JournalTab.h,J/Journal_SystemTab.h,I/IMenu.h,I/IVirtualMachine.h}; MIT.
// BSTEventSink, BSTSingletonSDM, FxDelegateHandler, JournalTab, IMenu, GFxFunctionHandler, IVirtualMachine, BSIntrusiveRefCounted: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, Contract and Identity tags, and physical mirror member names: GUESS(medium) STANDIN
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "thirdparty/scaleform/GRefCountImplStorageLayout.h"
#include "BSIntrusiveRefCountedStorageLayout.h"
namespace ResearchLayouts {
class MovieViewPointeeLayout;
class FxDelegatePointeeLayout;
class JournalTabStoragePrefixLayout : public GRefCountImplStorageLayout {
public:
    ~JournalTabStoragePrefixLayout() override;
    MovieViewPointeeLayout* view;
};
class MenuStoragePrefixLayout : public GRefCountImplStorageLayout {
public:
    ~MenuStoragePrefixLayout() override;
    MovieViewPointeeLayout* uiMovie;
    std::int8_t depthPriority;
    std::uint32_t menuFlags;
    std::uint32_t inputContext;
    FxDelegatePointeeLayout* fxDelegate;
};
class VirtualMachineStoragePrefixLayout : public BSIntrusiveRefCountedStorageLayout {
public:
    virtual ~VirtualMachineStoragePrefixLayout();
};
template<unsigned Identity> class EventInterfaceVptrPrefixLayout {
public:
    virtual ~EventInterfaceVptrPrefixLayout();
};
static_assert(sizeof(JournalTabStoragePrefixLayout) == 24, "public JournalTab storage");
static_assert(offsetof(JournalTabStoragePrefixLayout, view) == 16, "public movie pointer offset");
static_assert(sizeof(MenuStoragePrefixLayout) == 48, "public SE menu storage");
static_assert(offsetof(MenuStoragePrefixLayout, uiMovie) == 16, "public menu movie offset");
static_assert(offsetof(MenuStoragePrefixLayout, depthPriority) == 24, "public menu depth offset");
static_assert(offsetof(MenuStoragePrefixLayout, menuFlags) == 28, "public menu flags offset");
static_assert(offsetof(MenuStoragePrefixLayout, inputContext) == 32, "public menu context offset");
static_assert(offsetof(MenuStoragePrefixLayout, fxDelegate) == 40, "public delegate pointer offset");
static_assert(sizeof(VirtualMachineStoragePrefixLayout) == 16, "public VM refcounted interface storage");
static_assert(offsetof(VirtualMachineStoragePrefixLayout, _refCount) == 8, "public VM inherited count offset");
static_assert(sizeof(EventInterfaceVptrPrefixLayout<0>) == 8, "represented fieldless interface prefix");
// BSScript::Internal::VirtualMachine: EXE_RTTI
// Owner descriptor: .?AVVirtualMachine@Internal@BSScript@@
// Represented subobject at16: .?AUIVMObjectBindInterface@BSScript@@
// Represented subobject at24: .?AVIVMSaveLoadInterface@BSScript@@
// Represented subobject at32: .?AVIVMDebugInterface@BSScript@@
class BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayout : public VirtualMachineStoragePrefixLayout, public EventInterfaceVptrPrefixLayout<0>, public EventInterfaceVptrPrefixLayout<1>, public EventInterfaceVptrPrefixLayout<2> {
public:
    BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayout();
    ~BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayout) == 40, "represented contiguous interface prefix only");
struct BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayoutStorageLayout {
    VirtualMachineStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
};
static_assert(sizeof(BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayoutStorageLayout, interface0) == 16, "independent target subobject offset");
static_assert(offsetof(BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayoutStorageLayout, interface1) == 24, "independent target subobject offset");
static_assert(offsetof(BSScript__Internal__VirtualMachineInterfaceStoragePrefixLayoutStorageLayout, interface2) == 32, "independent target subobject offset");
// Journal_SystemTab: EXE_RTTI
// Owner descriptor: .?AVJournal_SystemTab@@
// Represented subobject at24: .?AV?$BSTEventSink@VBSSaveDataEvent@@@@
// Represented subobject at32: .?AV?$BSTEventSink@UBSGamerProfileEvent@@@@
// Represented subobject at40: .?AV?$BSTEventSink@UBGSSaveLoadManagerEvent@@@@
// Represented subobject at48: .?AV?$BSTEventSink@UBSRemoteGamepadEvent@@@@
class Journal_SystemTabInterfaceStoragePrefixLayout : public JournalTabStoragePrefixLayout, public EventInterfaceVptrPrefixLayout<3>, public EventInterfaceVptrPrefixLayout<4>, public EventInterfaceVptrPrefixLayout<5>, public EventInterfaceVptrPrefixLayout<6> {
public:
    Journal_SystemTabInterfaceStoragePrefixLayout();
    ~Journal_SystemTabInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(Journal_SystemTabInterfaceStoragePrefixLayout) == 56, "represented contiguous interface prefix only");
struct Journal_SystemTabInterfaceStoragePrefixLayoutStorageLayout {
    JournalTabStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
};
static_assert(sizeof(Journal_SystemTabInterfaceStoragePrefixLayoutStorageLayout) == 56, "physical prefix mirror");
static_assert(offsetof(Journal_SystemTabInterfaceStoragePrefixLayoutStorageLayout, interface0) == 24, "independent target subobject offset");
static_assert(offsetof(Journal_SystemTabInterfaceStoragePrefixLayoutStorageLayout, interface1) == 32, "independent target subobject offset");
static_assert(offsetof(Journal_SystemTabInterfaceStoragePrefixLayoutStorageLayout, interface2) == 40, "independent target subobject offset");
static_assert(offsetof(Journal_SystemTabInterfaceStoragePrefixLayoutStorageLayout, interface3) == 48, "independent target subobject offset");
// LoadWaitSpinner: EXE_RTTI
// Owner descriptor: .?AVLoadWaitSpinner@@
// Represented subobject at48: .?AV?$BSTEventSink@VBSSystemEvent@@@@
// Represented subobject at56: .?AV?$BSTEventSink@UBSGamerProfileEvent@@@@
// Represented subobject at64: .?AV?$BSTEventSink@UBGSSaveLoadManagerEvent@@@@
class LoadWaitSpinnerInterfaceStoragePrefixLayout : public MenuStoragePrefixLayout, public EventInterfaceVptrPrefixLayout<7>, public EventInterfaceVptrPrefixLayout<8>, public EventInterfaceVptrPrefixLayout<9> {
public:
    LoadWaitSpinnerInterfaceStoragePrefixLayout();
    ~LoadWaitSpinnerInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(LoadWaitSpinnerInterfaceStoragePrefixLayout) == 72, "represented contiguous interface prefix only");
struct LoadWaitSpinnerInterfaceStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
};
static_assert(sizeof(LoadWaitSpinnerInterfaceStoragePrefixLayoutStorageLayout) == 72, "physical prefix mirror");
static_assert(offsetof(LoadWaitSpinnerInterfaceStoragePrefixLayoutStorageLayout, interface0) == 48, "independent target subobject offset");
static_assert(offsetof(LoadWaitSpinnerInterfaceStoragePrefixLayoutStorageLayout, interface1) == 56, "independent target subobject offset");
static_assert(offsetof(LoadWaitSpinnerInterfaceStoragePrefixLayoutStorageLayout, interface2) == 64, "independent target subobject offset");
// MainMenu: EXE_RTTI
// Owner descriptor: .?AVMainMenu@@
// Represented subobject at48: .?AV?$BSTEventSink@VBSSystemEvent@@@@
// Represented subobject at56: .?AV?$BSTEventSink@VBSSaveDataEvent@@@@
// Represented subobject at64: .?AVGFxFunctionHandler@@
class MainMenuInterfaceStoragePrefixLayout : public MenuStoragePrefixLayout, public EventInterfaceVptrPrefixLayout<10>, public EventInterfaceVptrPrefixLayout<11>, public GRefCountImplStorageLayout {
public:
    MainMenuInterfaceStoragePrefixLayout();
    ~MainMenuInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(MainMenuInterfaceStoragePrefixLayout) == 80, "represented contiguous interface prefix only");
struct MainMenuInterfaceStoragePrefixLayoutStorageLayout {
    MenuStoragePrefixLayout primary;
    const void* const* interface0;
    const void* const* interface1;
    GRefCountImplStorageLayout interface2;
};
static_assert(sizeof(MainMenuInterfaceStoragePrefixLayoutStorageLayout) == 80, "physical prefix mirror");
static_assert(offsetof(MainMenuInterfaceStoragePrefixLayoutStorageLayout, interface0) == 48, "independent target subobject offset");
static_assert(offsetof(MainMenuInterfaceStoragePrefixLayoutStorageLayout, interface1) == 56, "independent target subobject offset");
static_assert(offsetof(MainMenuInterfaceStoragePrefixLayoutStorageLayout, interface2) == 64, "independent target subobject offset");
// PathManagerPositionPlayerAdapter: EXE_RTTI
// Owner descriptor: .?AVPathManagerPositionPlayerAdapter@@
// Represented subobject at0: .?AV?$BSTEventSink@UPositionPlayerEvent@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UTESSleepStartEvent@@@@
// Represented subobject at16: .?AV?$BSTEventSink@UTESSleepStopEvent@@@@
// Represented subobject at24: .?AV?$BSTEventSink@UTESWaitStartEvent@@@@
// Represented subobject at32: .?AV?$BSTEventSink@UTESWaitStopEvent@@@@
class PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayout : public EventInterfaceVptrPrefixLayout<12>, public EventInterfaceVptrPrefixLayout<13>, public EventInterfaceVptrPrefixLayout<14>, public EventInterfaceVptrPrefixLayout<15>, public EventInterfaceVptrPrefixLayout<16> {
public:
    PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayout();
    ~PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayout) == 40, "represented contiguous interface prefix only");
struct PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout {
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
    const void* const* interface4;
};
static_assert(sizeof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface0) == 0, "independent target subobject offset");
static_assert(offsetof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface1) == 8, "independent target subobject offset");
static_assert(offsetof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface2) == 16, "independent target subobject offset");
static_assert(offsetof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface3) == 24, "independent target subobject offset");
static_assert(offsetof(PathManagerPositionPlayerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface4) == 32, "independent target subobject offset");
// PlayerControls: EXE_RTTI
// Owner descriptor: .?AVPlayerControls@@
// Represented subobject at0: .?AV?$BSTEventSink@PEAVInputEvent@@@@
// Represented subobject at8: .?AV?$BSTEventSink@VMenuOpenCloseEvent@@@@
// Represented subobject at16: .?AV?$BSTEventSink@VMenuModeChangeEvent@@@@
// Represented subobject at24: .?AV?$BSTEventSink@UTESFurnitureEvent@@@@
class PlayerControlsInterfaceStoragePrefixLayout : public EventInterfaceVptrPrefixLayout<17>, public EventInterfaceVptrPrefixLayout<18>, public EventInterfaceVptrPrefixLayout<19>, public EventInterfaceVptrPrefixLayout<20> {
public:
    PlayerControlsInterfaceStoragePrefixLayout();
    ~PlayerControlsInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(PlayerControlsInterfaceStoragePrefixLayout) == 32, "represented contiguous interface prefix only");
struct PlayerControlsInterfaceStoragePrefixLayoutStorageLayout {
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
};
static_assert(sizeof(PlayerControlsInterfaceStoragePrefixLayoutStorageLayout) == 32, "physical prefix mirror");
static_assert(offsetof(PlayerControlsInterfaceStoragePrefixLayoutStorageLayout, interface0) == 0, "independent target subobject offset");
static_assert(offsetof(PlayerControlsInterfaceStoragePrefixLayoutStorageLayout, interface1) == 8, "independent target subobject offset");
static_assert(offsetof(PlayerControlsInterfaceStoragePrefixLayoutStorageLayout, interface2) == 16, "independent target subobject offset");
static_assert(offsetof(PlayerControlsInterfaceStoragePrefixLayoutStorageLayout, interface3) == 24, "independent target subobject offset");
// PlayerSleepWaitMovementControllerAdapter: EXE_RTTI
// Owner descriptor: .?AVPlayerSleepWaitMovementControllerAdapter@@
// Represented subobject at0: .?AV?$BSTEventSink@UTESSleepStartEvent@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UTESSleepStopEvent@@@@
// Represented subobject at16: .?AV?$BSTEventSink@UTESWaitStartEvent@@@@
// Represented subobject at24: .?AV?$BSTEventSink@UTESWaitStopEvent@@@@
// Represented subobject at32: .?AV?$BSTEventSink@UPositionPlayerEvent@@@@
class PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayout : public EventInterfaceVptrPrefixLayout<21>, public EventInterfaceVptrPrefixLayout<22>, public EventInterfaceVptrPrefixLayout<23>, public EventInterfaceVptrPrefixLayout<24>, public EventInterfaceVptrPrefixLayout<25> {
public:
    PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayout();
    ~PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayout) == 40, "represented contiguous interface prefix only");
struct PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout {
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
    const void* const* interface4;
};
static_assert(sizeof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface0) == 0, "independent target subobject offset");
static_assert(offsetof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface1) == 8, "independent target subobject offset");
static_assert(offsetof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface2) == 16, "independent target subobject offset");
static_assert(offsetof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface3) == 24, "independent target subobject offset");
static_assert(offsetof(PlayerSleepWaitMovementControllerAdapterInterfaceStoragePrefixLayoutStorageLayout, interface4) == 32, "independent target subobject offset");
// SkyrimSpeechRecognition: EXE_RTTI
// Owner descriptor: .?AVSkyrimSpeechRecognition@@
// Represented subobject at0: .?AV?$BSTEventSink@UDeviceConnected@SpeechRecognitionEvents@@@@
// Represented subobject at8: .?AV?$BSTEventSink@UDeviceReady@SpeechRecognitionEvents@@@@
// Represented subobject at16: .?AV?$BSTEventSink@UInterference@SpeechRecognitionEvents@@@@
// Represented subobject at24: .?AV?$BSTEventSink@URecognition@SpeechRecognitionEvents@@@@
// Represented subobject at32: .?AV?$BSTEventSink@VMenuOpenCloseEvent@@@@
class SkyrimSpeechRecognitionInterfaceStoragePrefixLayout : public EventInterfaceVptrPrefixLayout<26>, public EventInterfaceVptrPrefixLayout<27>, public EventInterfaceVptrPrefixLayout<28>, public EventInterfaceVptrPrefixLayout<29>, public EventInterfaceVptrPrefixLayout<30> {
public:
    SkyrimSpeechRecognitionInterfaceStoragePrefixLayout();
    ~SkyrimSpeechRecognitionInterfaceStoragePrefixLayout() override;
};
static_assert(sizeof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayout) == 40, "represented contiguous interface prefix only");
struct SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout {
    const void* const* interface0;
    const void* const* interface1;
    const void* const* interface2;
    const void* const* interface3;
    const void* const* interface4;
};
static_assert(sizeof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout) == 40, "physical prefix mirror");
static_assert(offsetof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout, interface0) == 0, "independent target subobject offset");
static_assert(offsetof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout, interface1) == 8, "independent target subobject offset");
static_assert(offsetof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout, interface2) == 16, "independent target subobject offset");
static_assert(offsetof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout, interface3) == 24, "independent target subobject offset");
static_assert(offsetof(SkyrimSpeechRecognitionInterfaceStoragePrefixLayoutStorageLayout, interface4) == 32, "independent target subobject offset");
}
