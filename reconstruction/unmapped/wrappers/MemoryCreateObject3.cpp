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
// 0x7d5680 MemoryCreateObject3::CreateFlightActionEndHandler
// 0x7d56e0 MemoryCreateObject3::CreateFlightActionEntryEndHandler
// 0x7d5740 MemoryCreateObject3::CreateFlightActionGrabHandler
// 0x7d57a0 MemoryCreateObject3::CreateFlightActionHandler
// 0x7d5800 MemoryCreateObject3::CreateFlightActionReleaseHandler
// 0x7d5860 MemoryCreateObject3::CreateFlightCrashLandStartHandler
// 0x7d58c0 MemoryCreateObject3::CreateFlightCruisingHandler
// 0x7d5920 MemoryCreateObject3::CreateFlightHoveringHandler
// 0x7d5980 MemoryCreateObject3::CreateFlightLandEndHandler
// 0x7d59e0 MemoryCreateObject3::CreateFlightLandHandler
// 0x7d5a40 MemoryCreateObject3::CreateFlightLandingHandler
// 0x7d5aa0 MemoryCreateObject3::CreateFlightPerchingHandler
// 0x7d5b00 MemoryCreateObject3::CreateFlightTakeOffHandler
// 0x7d5b60 MemoryCreateObject3::CreateGetUpEndHandler
// 0x7d5bc0 MemoryCreateObject3::CreateGetUpStartHandler
// 0x7d5c20 MemoryCreateObject3::CreateHeadTrackingOffHandler
// 0x7d5c80 MemoryCreateObject3::CreateHeadTrackingOnHandler
// 0x7d5ce0 MemoryCreateObject3::CreateHitFrameHandler
// 0x7d5d40 MemoryCreateObject3::CreateIdleDialogueEnterHandler
// 0x7d5da0 MemoryCreateObject3::CreateIdleDialogueExitHandler
// 0x7d5e00 MemoryCreateObject3::CreateInterruptCastHandler
// 0x7d5e60 MemoryCreateObject3::CreateJumpAnimEventHandler
// 0x7d5ec0 MemoryCreateObject3::CreateKillActorHandler
// 0x7d5f20 MemoryCreateObject3::CreateKillMoveEndHandler
// 0x7d5f80 MemoryCreateObject3::CreateKillMoveStartHandler
// 0x7d5fe0 MemoryCreateObject3::CreateLeftHandSpellCastHandler
// 0x7d6040 MemoryCreateObject3::CreateLeftHandSpellFireHandler
// 0x7d60a0 MemoryCreateObject3::CreateMTStateHandler
// 0x7d6100 MemoryCreateObject3::CreateMotionDrivenHandler
// 0x7d6160 MemoryCreateObject3::CreateMountDismountEndHandler
#include "MemoryCreateObject3.h"

HandlerFunctorBase* MemoryCreateObject3::CreateFlightActionEndHandler()
{
    return new FlightActionEndHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightActionEntryEndHandler()
{
    return new FlightActionEntryEndHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightActionGrabHandler()
{
    return new FlightActionGrabHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightActionHandler()
{
    return new FlightActionHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightActionReleaseHandler()
{
    return new FlightActionReleaseHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightCrashLandStartHandler()
{
    return new FlightCrashLandStartHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightCruisingHandler()
{
    return new FlightCruisingHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightHoveringHandler()
{
    return new FlightHoveringHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightLandEndHandler()
{
    return new FlightLandEndHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightLandHandler()
{
    return new FlightLandHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightLandingHandler()
{
    return new FlightLandingHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightPerchingHandler()
{
    return new FlightPerchingHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateFlightTakeOffHandler()
{
    return new FlightTakeOffHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateGetUpEndHandler()
{
    return new GetUpEndHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateGetUpStartHandler()
{
    return new GetUpStartHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateHeadTrackingOffHandler()
{
    return new HeadTrackingOffHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateHeadTrackingOnHandler()
{
    return new HeadTrackingOnHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateHitFrameHandler()
{
    return new HitFrameHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateIdleDialogueEnterHandler()
{
    return new IdleDialogueEnterHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateIdleDialogueExitHandler()
{
    return new IdleDialogueExitHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateInterruptCastHandler()
{
    return new InterruptCastHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateJumpAnimEventHandler()
{
    return new AnimHandlerCreators::JumpAnimEventHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateKillActorHandler()
{
    return new KillActorHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateKillMoveEndHandler()
{
    return new KillMoveEndHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateKillMoveStartHandler()
{
    return new KillMoveStartHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateLeftHandSpellCastHandler()
{
    return new LeftHandSpellCastHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateLeftHandSpellFireHandler()
{
    return new LeftHandSpellFireHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateMTStateHandler()
{
    return new MTStateHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateMotionDrivenHandler()
{
    return new MotionDrivenHandler();
}

HandlerFunctorBase* MemoryCreateObject3::CreateMountDismountEndHandler()
{
    return new MountDismountEndHandler();
}
