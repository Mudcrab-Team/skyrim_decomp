// Source exposure: mixed (pinned image RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTDerivedCreator::Create factory helpers.
// NPCAttachHandler, NPCDetachHandler, PairedStopHandler, PickNewIdleHandler: EXE_RTTI
// PitchOverrideEndHandler, PitchOverrideStartHandler, PlayerBedEnterHandler: EXE_RTTI
// PlayerChairEnterHandler, PlayerFurnitureExitHandler, RagdollStartHandler: EXE_RTTI
// RecoilStopHandler, RemoveRagdollHandler, RightHandSpellCastHandler, RightHandSpellFireHandler: EXE_RTTI
// RightHandWeaponDrawHandler, RightHandWeaponSheatheHandler, StaggeredStopHandler: EXE_RTTI
// StopMountCameraHandler, VampireFeedEndHandler, VoiceSpellCastHandler, VoiceSpellFireHandler: EXE_RTTI
// WeaponBeginDrawRightHandler, WeaponBeginSheatheRightHandler, WeaponLeftSwingHandler: EXE_RTTI
// WeaponRightSwingHandler, ZeroPitchHandler, ConsoleData, FaderData, RefHandleUIData: EXE_RTTI
// TESFormUIData: EXE_RTTI
// MemoryCreateObject4, MemoryFactoryManager, HandlerFunctorBase, UIMessageDataBase, creator methods and allocator symbols: GUESS(low) STANDIN; original signatures unknown.
// Adapted bodies: none
#pragma once
#include <cstddef>
#include <cstdint>

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
}

struct MemoryFactoryManager {
    static void* GetSingleton() {
        if (MemMgrGuard_369ac98 != 2u) {
            MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
        }
        return MemMgrInst_369a810;
    }
    static void* Alloc(std::size_t size, std::uint32_t align = 0u, bool alignReq = false) {
        return MemMgrAlloc_cde250(GetSingleton(), size, align, alignReq);
    }
};

// Stand-in for IHandlerFunctor<Actor, BSFixedStringCI> (inherits BSIntrusiveRefCounted; size 0x10).
class HandlerFunctorBase {
public:
    virtual ~HandlerFunctorBase();

    static void* operator new(std::size_t size) throw() {
        return MemoryFactoryManager::Alloc(size);
    }

    std::uint32_t refCount;

protected:
    HandlerFunctorBase() : refCount(0u) {}
};
static_assert(sizeof(HandlerFunctorBase) == 0x10, "HandlerFunctorBase size");

class NPCAttachHandler : public HandlerFunctorBase {
public:
    NPCAttachHandler() {}
    ~NPCAttachHandler() override;
};
static_assert(sizeof(NPCAttachHandler) == 0x10, "NPCAttachHandler size");

class NPCDetachHandler : public HandlerFunctorBase {
public:
    NPCDetachHandler() {}
    ~NPCDetachHandler() override;
};
static_assert(sizeof(NPCDetachHandler) == 0x10, "NPCDetachHandler size");

class PairedStopHandler : public HandlerFunctorBase {
public:
    PairedStopHandler() {}
    ~PairedStopHandler() override;
};
static_assert(sizeof(PairedStopHandler) == 0x10, "PairedStopHandler size");

class PickNewIdleHandler : public HandlerFunctorBase {
public:
    PickNewIdleHandler() {}
    ~PickNewIdleHandler() override;
};
static_assert(sizeof(PickNewIdleHandler) == 0x10, "PickNewIdleHandler size");

class PitchOverrideEndHandler : public HandlerFunctorBase {
public:
    PitchOverrideEndHandler() {}
    ~PitchOverrideEndHandler() override;
};
static_assert(sizeof(PitchOverrideEndHandler) == 0x10, "PitchOverrideEndHandler size");

class PitchOverrideStartHandler : public HandlerFunctorBase {
public:
    PitchOverrideStartHandler() {}
    ~PitchOverrideStartHandler() override;
};
static_assert(sizeof(PitchOverrideStartHandler) == 0x10, "PitchOverrideStartHandler size");

// RTTI derives from BedEnterHandler : IHandlerFunctor<Actor, BSFixedStringCI> (same 0x10 layout).
class PlayerBedEnterHandler : public HandlerFunctorBase {
public:
    PlayerBedEnterHandler() {}
    ~PlayerBedEnterHandler() override;
};
static_assert(sizeof(PlayerBedEnterHandler) == 0x10, "PlayerBedEnterHandler size");

// RTTI derives from ChairEnterHandler : IHandlerFunctor<Actor, BSFixedStringCI> (same 0x10 layout).
class PlayerChairEnterHandler : public HandlerFunctorBase {
public:
    PlayerChairEnterHandler() {}
    ~PlayerChairEnterHandler() override;
};
static_assert(sizeof(PlayerChairEnterHandler) == 0x10, "PlayerChairEnterHandler size");

class PlayerFurnitureExitHandler : public HandlerFunctorBase {
public:
    PlayerFurnitureExitHandler() {}
    ~PlayerFurnitureExitHandler() override;
};
static_assert(sizeof(PlayerFurnitureExitHandler) == 0x10, "PlayerFurnitureExitHandler size");

class RagdollStartHandler : public HandlerFunctorBase {
public:
    RagdollStartHandler() {}
    ~RagdollStartHandler() override;
};
static_assert(sizeof(RagdollStartHandler) == 0x10, "RagdollStartHandler size");

class RecoilStopHandler : public HandlerFunctorBase {
public:
    RecoilStopHandler() {}
    ~RecoilStopHandler() override;
};
static_assert(sizeof(RecoilStopHandler) == 0x10, "RecoilStopHandler size");

class RemoveRagdollHandler : public HandlerFunctorBase {
public:
    RemoveRagdollHandler() {}
    ~RemoveRagdollHandler() override;
};
static_assert(sizeof(RemoveRagdollHandler) == 0x10, "RemoveRagdollHandler size");

class RightHandSpellCastHandler : public HandlerFunctorBase {
public:
    RightHandSpellCastHandler() {}
    ~RightHandSpellCastHandler() override;
};
static_assert(sizeof(RightHandSpellCastHandler) == 0x10, "RightHandSpellCastHandler size");

class RightHandSpellFireHandler : public HandlerFunctorBase {
public:
    RightHandSpellFireHandler() {}
    ~RightHandSpellFireHandler() override;
};
static_assert(sizeof(RightHandSpellFireHandler) == 0x10, "RightHandSpellFireHandler size");

class RightHandWeaponDrawHandler : public HandlerFunctorBase {
public:
    RightHandWeaponDrawHandler() {}
    ~RightHandWeaponDrawHandler() override;
};
static_assert(sizeof(RightHandWeaponDrawHandler) == 0x10, "RightHandWeaponDrawHandler size");

class RightHandWeaponSheatheHandler : public HandlerFunctorBase {
public:
    RightHandWeaponSheatheHandler() {}
    ~RightHandWeaponSheatheHandler() override;
};
static_assert(sizeof(RightHandWeaponSheatheHandler) == 0x10, "RightHandWeaponSheatheHandler size");

class StaggeredStopHandler : public HandlerFunctorBase {
public:
    StaggeredStopHandler() {}
    ~StaggeredStopHandler() override;
};
static_assert(sizeof(StaggeredStopHandler) == 0x10, "StaggeredStopHandler size");

class StopMountCameraHandler : public HandlerFunctorBase {
public:
    StopMountCameraHandler() {}
    ~StopMountCameraHandler() override;
};
static_assert(sizeof(StopMountCameraHandler) == 0x10, "StopMountCameraHandler size");

class VampireFeedEndHandler : public HandlerFunctorBase {
public:
    VampireFeedEndHandler() {}
    ~VampireFeedEndHandler() override;
};
static_assert(sizeof(VampireFeedEndHandler) == 0x10, "VampireFeedEndHandler size");

class VoiceSpellCastHandler : public HandlerFunctorBase {
public:
    VoiceSpellCastHandler() {}
    ~VoiceSpellCastHandler() override;
};
static_assert(sizeof(VoiceSpellCastHandler) == 0x10, "VoiceSpellCastHandler size");

class VoiceSpellFireHandler : public HandlerFunctorBase {
public:
    VoiceSpellFireHandler() {}
    ~VoiceSpellFireHandler() override;
};
static_assert(sizeof(VoiceSpellFireHandler) == 0x10, "VoiceSpellFireHandler size");

class WeaponBeginDrawRightHandler : public HandlerFunctorBase {
public:
    WeaponBeginDrawRightHandler() {}
    ~WeaponBeginDrawRightHandler() override;
};
static_assert(sizeof(WeaponBeginDrawRightHandler) == 0x10, "WeaponBeginDrawRightHandler size");

class WeaponBeginSheatheRightHandler : public HandlerFunctorBase {
public:
    WeaponBeginSheatheRightHandler() {}
    ~WeaponBeginSheatheRightHandler() override;
};
static_assert(sizeof(WeaponBeginSheatheRightHandler) == 0x10, "WeaponBeginSheatheRightHandler size");

class WeaponLeftSwingHandler : public HandlerFunctorBase {
public:
    WeaponLeftSwingHandler() {}
    ~WeaponLeftSwingHandler() override;
};
static_assert(sizeof(WeaponLeftSwingHandler) == 0x10, "WeaponLeftSwingHandler size");

class WeaponRightSwingHandler : public HandlerFunctorBase {
public:
    WeaponRightSwingHandler() {}
    ~WeaponRightSwingHandler() override;
};
static_assert(sizeof(WeaponRightSwingHandler) == 0x10, "WeaponRightSwingHandler size");

class ZeroPitchHandler : public HandlerFunctorBase {
public:
    ZeroPitchHandler() {}
    ~ZeroPitchHandler() override;
};
static_assert(sizeof(ZeroPitchHandler) == 0x10, "ZeroPitchHandler size");

// Stand-in for IUIMessageData (size 0x10; distinct name avoids redefining BSUIScaleformData.h's IUIMessageData).
class UIMessageDataBase {
public:
    virtual ~UIMessageDataBase();

    static void* operator new(std::size_t size) throw() {
        return MemoryFactoryManager::Alloc(size);
    }

    bool unk08;
    bool unk09;

protected:
    UIMessageDataBase() : unk08(false), unk09(false) {}
};
static_assert(sizeof(UIMessageDataBase) == 0x10, "UIMessageDataBase size");

class ConsoleData : public UIMessageDataBase {
public:
    void* str;
    std::uint32_t pickRef;
    void* file;
    std::uint32_t type;

    ConsoleData() : str(nullptr), pickRef(0u), file(nullptr), type(4u) {}
    ~ConsoleData() override;
};
static_assert(sizeof(ConsoleData) == 0x30, "ConsoleData size");

struct FaderData : public UIMessageDataBase {
    void* unk10;
    std::uint8_t unk18;
    std::uint32_t unk1c;
    float fadeDuration;
    bool unk24;
    bool unk25;
    std::uint8_t unk26;
    std::uint8_t unk27;

    FaderData()
        : unk10(nullptr),
          unk18(3u),
          unk1c(0u),
          fadeDuration(1.0f),
          unk24(true),
          unk25(true),
          unk26(0u),
          unk27(0u) {}
    ~FaderData() override;
};
static_assert(sizeof(FaderData) == 0x28, "FaderData size");

struct RefHandleUIData : public UIMessageDataBase {
    std::uint32_t refHandle;

    RefHandleUIData() : refHandle(0u) {}
    ~RefHandleUIData() override;
};
static_assert(sizeof(RefHandleUIData) == 0x18, "RefHandleUIData size");

struct TESFormUIData : public UIMessageDataBase {
    void* form;

    TESFormUIData() {}
    ~TESFormUIData() override;
};
static_assert(sizeof(TESFormUIData) == 0x18, "TESFormUIData size");

struct MemoryCreateObject4 {
    HandlerFunctorBase* CreateNPCAttachHandler();
    HandlerFunctorBase* CreateNPCDetachHandler();
    HandlerFunctorBase* CreatePairedStopHandler();
    HandlerFunctorBase* CreatePickNewIdleHandler();
    HandlerFunctorBase* CreatePitchOverrideEndHandler();
    HandlerFunctorBase* CreatePitchOverrideStartHandler();
    HandlerFunctorBase* CreatePlayerBedEnterHandler();
    HandlerFunctorBase* CreatePlayerChairEnterHandler();
    HandlerFunctorBase* CreatePlayerFurnitureExitHandler();
    HandlerFunctorBase* CreateRagdollStartHandler();
    HandlerFunctorBase* CreateRecoilStopHandler();
    HandlerFunctorBase* CreateRemoveRagdollHandler();
    HandlerFunctorBase* CreateRightHandSpellCastHandler();
    HandlerFunctorBase* CreateRightHandSpellFireHandler();
    HandlerFunctorBase* CreateRightHandWeaponDrawHandler();
    HandlerFunctorBase* CreateRightHandWeaponSheatheHandler();
    HandlerFunctorBase* CreateStaggeredStopHandler();
    HandlerFunctorBase* CreateStopMountCameraHandler();
    HandlerFunctorBase* CreateVampireFeedEndHandler();
    HandlerFunctorBase* CreateVoiceSpellCastHandler();
    HandlerFunctorBase* CreateVoiceSpellFireHandler();
    HandlerFunctorBase* CreateWeaponBeginDrawRightHandler();
    HandlerFunctorBase* CreateWeaponBeginSheatheRightHandler();
    HandlerFunctorBase* CreateWeaponLeftSwingHandler();
    HandlerFunctorBase* CreateWeaponRightSwingHandler();
    HandlerFunctorBase* CreateZeroPitchHandler();
    UIMessageDataBase* CreateConsoleData();
    UIMessageDataBase* CreateFaderData();
    UIMessageDataBase* CreateRefHandleUIData();
    UIMessageDataBase* CreateTESFormUIData();
};
