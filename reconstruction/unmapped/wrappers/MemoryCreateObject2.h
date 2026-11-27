// Source exposure: mixed (pinned image RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTDerivedCreator::Create factory helpers.
// AnimationObjectDrawHandler, AnimationObjectLoadHandler, AnticipateAttackHandler: EXE_RTTI
// ArrowAttachHandler, ArrowDetachHandler, ArrowReleaseHandler, AttackStopHandler: EXE_RTTI
// AttackWinEndHandler, AttackWinStartHandler, BedEnterHandler, BedFurnitureExitHandler: EXE_RTTI
// BowDrawnHandler, BowReleaseHandler, BowZoomStartHandler, BowZoomStopHandler: EXE_RTTI
// CameraOverrideStartHandler, CameraOverrideStopHandler, CameraShakeHandler: EXE_RTTI
// ChairEnterHandler, ChairFurnitureExitHandler, DeathEmoteHandler, DeathStopHandler: EXE_RTTI
// DecapitateHandler, DisableCharacterBumperHandler, DisableCharacterPitchHandler: EXE_RTTI
// EnableCharacterBumperHandler, EnableCharacterPitchHandler, EndSummonAnimationHandler: EXE_RTTI
// ExitCartBeginHandler, ExitCartEndHandler: EXE_RTTI
// MemoryCreateObject2, MemoryFactoryManager, HandlerFunctorBase, creator methods and allocator symbols: GUESS(low) STANDIN; original signatures unknown.
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

class AnimationObjectDrawHandler : public HandlerFunctorBase {
public:
    AnimationObjectDrawHandler() {}
    ~AnimationObjectDrawHandler() override;
};
static_assert(sizeof(AnimationObjectDrawHandler) == 0x10, "AnimationObjectDrawHandler size");

class AnimationObjectLoadHandler : public HandlerFunctorBase {
public:
    AnimationObjectLoadHandler() {}
    ~AnimationObjectLoadHandler() override;
};
static_assert(sizeof(AnimationObjectLoadHandler) == 0x10, "AnimationObjectLoadHandler size");

class AnticipateAttackHandler : public HandlerFunctorBase {
public:
    AnticipateAttackHandler() {}
    ~AnticipateAttackHandler() override;
};
static_assert(sizeof(AnticipateAttackHandler) == 0x10, "AnticipateAttackHandler size");

class ArrowAttachHandler : public HandlerFunctorBase {
public:
    ArrowAttachHandler() {}
    ~ArrowAttachHandler() override;
};
static_assert(sizeof(ArrowAttachHandler) == 0x10, "ArrowAttachHandler size");

class ArrowDetachHandler : public HandlerFunctorBase {
public:
    ArrowDetachHandler() {}
    ~ArrowDetachHandler() override;
};
static_assert(sizeof(ArrowDetachHandler) == 0x10, "ArrowDetachHandler size");

class ArrowReleaseHandler : public HandlerFunctorBase {
public:
    ArrowReleaseHandler() {}
    ~ArrowReleaseHandler() override;
};
static_assert(sizeof(ArrowReleaseHandler) == 0x10, "ArrowReleaseHandler size");

class AttackStopHandler : public HandlerFunctorBase {
public:
    AttackStopHandler() {}
    ~AttackStopHandler() override;
};
static_assert(sizeof(AttackStopHandler) == 0x10, "AttackStopHandler size");

class AttackWinEndHandler : public HandlerFunctorBase {
public:
    AttackWinEndHandler() {}
    ~AttackWinEndHandler() override;
};
static_assert(sizeof(AttackWinEndHandler) == 0x10, "AttackWinEndHandler size");

class AttackWinStartHandler : public HandlerFunctorBase {
public:
    AttackWinStartHandler() {}
    ~AttackWinStartHandler() override;
};
static_assert(sizeof(AttackWinStartHandler) == 0x10, "AttackWinStartHandler size");

class BedEnterHandler : public HandlerFunctorBase {
public:
    BedEnterHandler() {}
    ~BedEnterHandler() override;
};
static_assert(sizeof(BedEnterHandler) == 0x10, "BedEnterHandler size");

class BedFurnitureExitHandler : public HandlerFunctorBase {
public:
    BedFurnitureExitHandler() {}
    ~BedFurnitureExitHandler() override;
};
static_assert(sizeof(BedFurnitureExitHandler) == 0x10, "BedFurnitureExitHandler size");

class BowDrawnHandler : public HandlerFunctorBase {
public:
    BowDrawnHandler() {}
    ~BowDrawnHandler() override;
};
static_assert(sizeof(BowDrawnHandler) == 0x10, "BowDrawnHandler size");

class BowReleaseHandler : public HandlerFunctorBase {
public:
    BowReleaseHandler() {}
    ~BowReleaseHandler() override;
};
static_assert(sizeof(BowReleaseHandler) == 0x10, "BowReleaseHandler size");

class BowZoomStartHandler : public HandlerFunctorBase {
public:
    BowZoomStartHandler() {}
    ~BowZoomStartHandler() override;
};
static_assert(sizeof(BowZoomStartHandler) == 0x10, "BowZoomStartHandler size");

class BowZoomStopHandler : public HandlerFunctorBase {
public:
    BowZoomStopHandler() {}
    ~BowZoomStopHandler() override;
};
static_assert(sizeof(BowZoomStopHandler) == 0x10, "BowZoomStopHandler size");

class CameraOverrideStartHandler : public HandlerFunctorBase {
public:
    CameraOverrideStartHandler() {}
    ~CameraOverrideStartHandler() override;
};
static_assert(sizeof(CameraOverrideStartHandler) == 0x10, "CameraOverrideStartHandler size");

class CameraOverrideStopHandler : public HandlerFunctorBase {
public:
    CameraOverrideStopHandler() {}
    ~CameraOverrideStopHandler() override;
};
static_assert(sizeof(CameraOverrideStopHandler) == 0x10, "CameraOverrideStopHandler size");

class CameraShakeHandler : public HandlerFunctorBase {
public:
    CameraShakeHandler() {}
    ~CameraShakeHandler() override;
};
static_assert(sizeof(CameraShakeHandler) == 0x10, "CameraShakeHandler size");

class ChairEnterHandler : public HandlerFunctorBase {
public:
    ChairEnterHandler() {}
    ~ChairEnterHandler() override;
};
static_assert(sizeof(ChairEnterHandler) == 0x10, "ChairEnterHandler size");

class ChairFurnitureExitHandler : public HandlerFunctorBase {
public:
    ChairFurnitureExitHandler() {}
    ~ChairFurnitureExitHandler() override;
};
static_assert(sizeof(ChairFurnitureExitHandler) == 0x10, "ChairFurnitureExitHandler size");

class DeathEmoteHandler : public HandlerFunctorBase {
public:
    DeathEmoteHandler() {}
    ~DeathEmoteHandler() override;
};
static_assert(sizeof(DeathEmoteHandler) == 0x10, "DeathEmoteHandler size");

class DeathStopHandler : public HandlerFunctorBase {
public:
    DeathStopHandler() {}
    ~DeathStopHandler() override;
};
static_assert(sizeof(DeathStopHandler) == 0x10, "DeathStopHandler size");

class DecapitateHandler : public HandlerFunctorBase {
public:
    DecapitateHandler() {}
    ~DecapitateHandler() override;
};
static_assert(sizeof(DecapitateHandler) == 0x10, "DecapitateHandler size");

class DisableCharacterBumperHandler : public HandlerFunctorBase {
public:
    DisableCharacterBumperHandler() {}
    ~DisableCharacterBumperHandler() override;
};
static_assert(sizeof(DisableCharacterBumperHandler) == 0x10, "DisableCharacterBumperHandler size");

class DisableCharacterPitchHandler : public HandlerFunctorBase {
public:
    DisableCharacterPitchHandler() {}
    ~DisableCharacterPitchHandler() override;
};
static_assert(sizeof(DisableCharacterPitchHandler) == 0x10, "DisableCharacterPitchHandler size");

class EnableCharacterBumperHandler : public HandlerFunctorBase {
public:
    EnableCharacterBumperHandler() {}
    ~EnableCharacterBumperHandler() override;
};
static_assert(sizeof(EnableCharacterBumperHandler) == 0x10, "EnableCharacterBumperHandler size");

class EnableCharacterPitchHandler : public HandlerFunctorBase {
public:
    EnableCharacterPitchHandler() {}
    ~EnableCharacterPitchHandler() override;
};
static_assert(sizeof(EnableCharacterPitchHandler) == 0x10, "EnableCharacterPitchHandler size");

class EndSummonAnimationHandler : public HandlerFunctorBase {
public:
    EndSummonAnimationHandler() {}
    ~EndSummonAnimationHandler() override;
};
static_assert(sizeof(EndSummonAnimationHandler) == 0x10, "EndSummonAnimationHandler size");

class ExitCartBeginHandler : public HandlerFunctorBase {
public:
    ExitCartBeginHandler() {}
    ~ExitCartBeginHandler() override;
};
static_assert(sizeof(ExitCartBeginHandler) == 0x10, "ExitCartBeginHandler size");

class ExitCartEndHandler : public HandlerFunctorBase {
public:
    ExitCartEndHandler() {}
    ~ExitCartEndHandler() override;
};
static_assert(sizeof(ExitCartEndHandler) == 0x10, "ExitCartEndHandler size");

struct MemoryCreateObject2 {
    HandlerFunctorBase* CreateAnimationObjectDrawHandler();
    HandlerFunctorBase* CreateAnimationObjectLoadHandler();
    HandlerFunctorBase* CreateAnticipateAttackHandler();
    HandlerFunctorBase* CreateArrowAttachHandler();
    HandlerFunctorBase* CreateArrowDetachHandler();
    HandlerFunctorBase* CreateArrowReleaseHandler();
    HandlerFunctorBase* CreateAttackStopHandler();
    HandlerFunctorBase* CreateAttackWinEndHandler();
    HandlerFunctorBase* CreateAttackWinStartHandler();
    HandlerFunctorBase* CreateBedEnterHandler();
    HandlerFunctorBase* CreateBedFurnitureExitHandler();
    HandlerFunctorBase* CreateBowDrawnHandler();
    HandlerFunctorBase* CreateBowReleaseHandler();
    HandlerFunctorBase* CreateBowZoomStartHandler();
    HandlerFunctorBase* CreateBowZoomStopHandler();
    HandlerFunctorBase* CreateCameraOverrideStartHandler();
    HandlerFunctorBase* CreateCameraOverrideStopHandler();
    HandlerFunctorBase* CreateCameraShakeHandler();
    HandlerFunctorBase* CreateChairEnterHandler();
    HandlerFunctorBase* CreateChairFurnitureExitHandler();
    HandlerFunctorBase* CreateDeathEmoteHandler();
    HandlerFunctorBase* CreateDeathStopHandler();
    HandlerFunctorBase* CreateDecapitateHandler();
    HandlerFunctorBase* CreateDisableCharacterBumperHandler();
    HandlerFunctorBase* CreateDisableCharacterPitchHandler();
    HandlerFunctorBase* CreateEnableCharacterBumperHandler();
    HandlerFunctorBase* CreateEnableCharacterPitchHandler();
    HandlerFunctorBase* CreateEndSummonAnimationHandler();
    HandlerFunctorBase* CreateExitCartBeginHandler();
    HandlerFunctorBase* CreateExitCartEndHandler();
};
