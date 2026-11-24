// Source exposure: mixed (pinned image RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original structural reconstruction of Bethesda BSTDerivedCreator::Create factory helpers.
// FlightActionEndHandler, FlightActionEntryEndHandler, FlightActionGrabHandler: EXE_RTTI
// FlightActionHandler, FlightActionReleaseHandler, FlightCrashLandStartHandler: EXE_RTTI
// FlightCruisingHandler, FlightHoveringHandler, FlightLandEndHandler, FlightLandHandler: EXE_RTTI
// FlightLandingHandler, FlightPerchingHandler, FlightTakeOffHandler, GetUpEndHandler: EXE_RTTI
// GetUpStartHandler, HeadTrackingOffHandler, HeadTrackingOnHandler, HitFrameHandler: EXE_RTTI
// IdleDialogueEnterHandler, IdleDialogueExitHandler, InterruptCastHandler, JumpAnimEventHandler: EXE_RTTI
// KillActorHandler, KillMoveEndHandler, KillMoveStartHandler, LeftHandSpellCastHandler: EXE_RTTI
// LeftHandSpellFireHandler, MTStateHandler, MotionDrivenHandler, MountDismountEndHandler: EXE_RTTI
// MemoryCreateObject3, MemoryFactoryManager, HandlerFunctorBase, AnimHandlerCreators, creator methods and allocator symbols: GUESS(low) STANDIN; original signatures unknown.
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

class FlightActionEndHandler : public HandlerFunctorBase {
public:
    FlightActionEndHandler() {}
    ~FlightActionEndHandler() override;
};
static_assert(sizeof(FlightActionEndHandler) == 0x10, "FlightActionEndHandler size");

class FlightActionEntryEndHandler : public HandlerFunctorBase {
public:
    FlightActionEntryEndHandler() {}
    ~FlightActionEntryEndHandler() override;
};
static_assert(sizeof(FlightActionEntryEndHandler) == 0x10, "FlightActionEntryEndHandler size");

class FlightActionGrabHandler : public HandlerFunctorBase {
public:
    FlightActionGrabHandler() {}
    ~FlightActionGrabHandler() override;
};
static_assert(sizeof(FlightActionGrabHandler) == 0x10, "FlightActionGrabHandler size");

class FlightActionHandler : public HandlerFunctorBase {
public:
    FlightActionHandler() {}
    ~FlightActionHandler() override;
};
static_assert(sizeof(FlightActionHandler) == 0x10, "FlightActionHandler size");

class FlightActionReleaseHandler : public HandlerFunctorBase {
public:
    FlightActionReleaseHandler() {}
    ~FlightActionReleaseHandler() override;
};
static_assert(sizeof(FlightActionReleaseHandler) == 0x10, "FlightActionReleaseHandler size");

class FlightCrashLandStartHandler : public HandlerFunctorBase {
public:
    FlightCrashLandStartHandler() {}
    ~FlightCrashLandStartHandler() override;
};
static_assert(sizeof(FlightCrashLandStartHandler) == 0x10, "FlightCrashLandStartHandler size");

class FlightCruisingHandler : public HandlerFunctorBase {
public:
    FlightCruisingHandler() {}
    ~FlightCruisingHandler() override;
};
static_assert(sizeof(FlightCruisingHandler) == 0x10, "FlightCruisingHandler size");

class FlightHoveringHandler : public HandlerFunctorBase {
public:
    FlightHoveringHandler() {}
    ~FlightHoveringHandler() override;
};
static_assert(sizeof(FlightHoveringHandler) == 0x10, "FlightHoveringHandler size");

class FlightLandEndHandler : public HandlerFunctorBase {
public:
    FlightLandEndHandler() {}
    ~FlightLandEndHandler() override;
};
static_assert(sizeof(FlightLandEndHandler) == 0x10, "FlightLandEndHandler size");

class FlightLandHandler : public HandlerFunctorBase {
public:
    FlightLandHandler() {}
    ~FlightLandHandler() override;
};
static_assert(sizeof(FlightLandHandler) == 0x10, "FlightLandHandler size");

class FlightLandingHandler : public HandlerFunctorBase {
public:
    FlightLandingHandler() {}
    ~FlightLandingHandler() override;
};
static_assert(sizeof(FlightLandingHandler) == 0x10, "FlightLandingHandler size");

class FlightPerchingHandler : public HandlerFunctorBase {
public:
    FlightPerchingHandler() {}
    ~FlightPerchingHandler() override;
};
static_assert(sizeof(FlightPerchingHandler) == 0x10, "FlightPerchingHandler size");

class FlightTakeOffHandler : public HandlerFunctorBase {
public:
    FlightTakeOffHandler() {}
    ~FlightTakeOffHandler() override;
};
static_assert(sizeof(FlightTakeOffHandler) == 0x10, "FlightTakeOffHandler size");

class GetUpEndHandler : public HandlerFunctorBase {
public:
    GetUpEndHandler() {}
    ~GetUpEndHandler() override;
};
static_assert(sizeof(GetUpEndHandler) == 0x10, "GetUpEndHandler size");

class GetUpStartHandler : public HandlerFunctorBase {
public:
    GetUpStartHandler() {}
    ~GetUpStartHandler() override;
};
static_assert(sizeof(GetUpStartHandler) == 0x10, "GetUpStartHandler size");

class HeadTrackingOffHandler : public HandlerFunctorBase {
public:
    HeadTrackingOffHandler() {}
    ~HeadTrackingOffHandler() override;
};
static_assert(sizeof(HeadTrackingOffHandler) == 0x10, "HeadTrackingOffHandler size");

class HeadTrackingOnHandler : public HandlerFunctorBase {
public:
    HeadTrackingOnHandler() {}
    ~HeadTrackingOnHandler() override;
};
static_assert(sizeof(HeadTrackingOnHandler) == 0x10, "HeadTrackingOnHandler size");

class HitFrameHandler : public HandlerFunctorBase {
public:
    HitFrameHandler() {}
    ~HitFrameHandler() override;
};
static_assert(sizeof(HitFrameHandler) == 0x10, "HitFrameHandler size");

class IdleDialogueEnterHandler : public HandlerFunctorBase {
public:
    IdleDialogueEnterHandler() {}
    ~IdleDialogueEnterHandler() override;
};
static_assert(sizeof(IdleDialogueEnterHandler) == 0x10, "IdleDialogueEnterHandler size");

class IdleDialogueExitHandler : public HandlerFunctorBase {
public:
    IdleDialogueExitHandler() {}
    ~IdleDialogueExitHandler() override;
};
static_assert(sizeof(IdleDialogueExitHandler) == 0x10, "IdleDialogueExitHandler size");

class InterruptCastHandler : public HandlerFunctorBase {
public:
    InterruptCastHandler() {}
    ~InterruptCastHandler() override;
};
static_assert(sizeof(InterruptCastHandler) == 0x10, "InterruptCastHandler size");

// Scoped to avoid redefining reconstruction/skyrim/controls/JumpAnimEventHandler.h.
namespace AnimHandlerCreators {
class JumpAnimEventHandler : public HandlerFunctorBase {
public:
    JumpAnimEventHandler() {}
    ~JumpAnimEventHandler() override;
};
static_assert(sizeof(JumpAnimEventHandler) == 0x10, "JumpAnimEventHandler size");
}

class KillActorHandler : public HandlerFunctorBase {
public:
    KillActorHandler() {}
    ~KillActorHandler() override;
};
static_assert(sizeof(KillActorHandler) == 0x10, "KillActorHandler size");

class KillMoveEndHandler : public HandlerFunctorBase {
public:
    KillMoveEndHandler() {}
    ~KillMoveEndHandler() override;
};
static_assert(sizeof(KillMoveEndHandler) == 0x10, "KillMoveEndHandler size");

class KillMoveStartHandler : public HandlerFunctorBase {
public:
    KillMoveStartHandler() {}
    ~KillMoveStartHandler() override;
};
static_assert(sizeof(KillMoveStartHandler) == 0x10, "KillMoveStartHandler size");

class LeftHandSpellCastHandler : public HandlerFunctorBase {
public:
    LeftHandSpellCastHandler() {}
    ~LeftHandSpellCastHandler() override;
};
static_assert(sizeof(LeftHandSpellCastHandler) == 0x10, "LeftHandSpellCastHandler size");

class LeftHandSpellFireHandler : public HandlerFunctorBase {
public:
    LeftHandSpellFireHandler() {}
    ~LeftHandSpellFireHandler() override;
};
static_assert(sizeof(LeftHandSpellFireHandler) == 0x10, "LeftHandSpellFireHandler size");

class MTStateHandler : public HandlerFunctorBase {
public:
    MTStateHandler() {}
    ~MTStateHandler() override;
};
static_assert(sizeof(MTStateHandler) == 0x10, "MTStateHandler size");

class MotionDrivenHandler : public HandlerFunctorBase {
public:
    MotionDrivenHandler() {}
    ~MotionDrivenHandler() override;
};
static_assert(sizeof(MotionDrivenHandler) == 0x10, "MotionDrivenHandler size");

class MountDismountEndHandler : public HandlerFunctorBase {
public:
    MountDismountEndHandler() {}
    ~MountDismountEndHandler() override;
};
static_assert(sizeof(MountDismountEndHandler) == 0x10, "MountDismountEndHandler size");

struct MemoryCreateObject3 {
    HandlerFunctorBase* CreateFlightActionEndHandler();
    HandlerFunctorBase* CreateFlightActionEntryEndHandler();
    HandlerFunctorBase* CreateFlightActionGrabHandler();
    HandlerFunctorBase* CreateFlightActionHandler();
    HandlerFunctorBase* CreateFlightActionReleaseHandler();
    HandlerFunctorBase* CreateFlightCrashLandStartHandler();
    HandlerFunctorBase* CreateFlightCruisingHandler();
    HandlerFunctorBase* CreateFlightHoveringHandler();
    HandlerFunctorBase* CreateFlightLandEndHandler();
    HandlerFunctorBase* CreateFlightLandHandler();
    HandlerFunctorBase* CreateFlightLandingHandler();
    HandlerFunctorBase* CreateFlightPerchingHandler();
    HandlerFunctorBase* CreateFlightTakeOffHandler();
    HandlerFunctorBase* CreateGetUpEndHandler();
    HandlerFunctorBase* CreateGetUpStartHandler();
    HandlerFunctorBase* CreateHeadTrackingOffHandler();
    HandlerFunctorBase* CreateHeadTrackingOnHandler();
    HandlerFunctorBase* CreateHitFrameHandler();
    HandlerFunctorBase* CreateIdleDialogueEnterHandler();
    HandlerFunctorBase* CreateIdleDialogueExitHandler();
    HandlerFunctorBase* CreateInterruptCastHandler();
    HandlerFunctorBase* CreateJumpAnimEventHandler();
    HandlerFunctorBase* CreateKillActorHandler();
    HandlerFunctorBase* CreateKillMoveEndHandler();
    HandlerFunctorBase* CreateKillMoveStartHandler();
    HandlerFunctorBase* CreateLeftHandSpellCastHandler();
    HandlerFunctorBase* CreateLeftHandSpellFireHandler();
    HandlerFunctorBase* CreateMTStateHandler();
    HandlerFunctorBase* CreateMotionDrivenHandler();
    HandlerFunctorBase* CreateMountDismountEndHandler();
};
