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
// 0x7d4b40 MemoryCreateObject2::CreateAnimationObjectDrawHandler
// 0x7d4ba0 MemoryCreateObject2::CreateAnimationObjectLoadHandler
// 0x7d4c00 MemoryCreateObject2::CreateAnticipateAttackHandler
// 0x7d4c60 MemoryCreateObject2::CreateArrowAttachHandler
// 0x7d4cc0 MemoryCreateObject2::CreateArrowDetachHandler
// 0x7d4d20 MemoryCreateObject2::CreateArrowReleaseHandler
// 0x7d4d80 MemoryCreateObject2::CreateAttackStopHandler
// 0x7d4de0 MemoryCreateObject2::CreateAttackWinEndHandler
// 0x7d4e40 MemoryCreateObject2::CreateAttackWinStartHandler
// 0x7d4ea0 MemoryCreateObject2::CreateBedEnterHandler
// 0x7d4f00 MemoryCreateObject2::CreateBedFurnitureExitHandler
// 0x7d4f60 MemoryCreateObject2::CreateBowDrawnHandler
// 0x7d4fc0 MemoryCreateObject2::CreateBowReleaseHandler
// 0x7d5020 MemoryCreateObject2::CreateBowZoomStartHandler
// 0x7d5080 MemoryCreateObject2::CreateBowZoomStopHandler
// 0x7d50e0 MemoryCreateObject2::CreateCameraOverrideStartHandler
// 0x7d5140 MemoryCreateObject2::CreateCameraOverrideStopHandler
// 0x7d51a0 MemoryCreateObject2::CreateCameraShakeHandler
// 0x7d5200 MemoryCreateObject2::CreateChairEnterHandler
// 0x7d5260 MemoryCreateObject2::CreateChairFurnitureExitHandler
// 0x7d52c0 MemoryCreateObject2::CreateDeathEmoteHandler
// 0x7d5320 MemoryCreateObject2::CreateDeathStopHandler
// 0x7d5380 MemoryCreateObject2::CreateDecapitateHandler
// 0x7d53e0 MemoryCreateObject2::CreateDisableCharacterBumperHandler
// 0x7d5440 MemoryCreateObject2::CreateDisableCharacterPitchHandler
// 0x7d54a0 MemoryCreateObject2::CreateEnableCharacterBumperHandler
// 0x7d5500 MemoryCreateObject2::CreateEnableCharacterPitchHandler
// 0x7d5560 MemoryCreateObject2::CreateEndSummonAnimationHandler
// 0x7d55c0 MemoryCreateObject2::CreateExitCartBeginHandler
// 0x7d5620 MemoryCreateObject2::CreateExitCartEndHandler
#include "MemoryCreateObject2.h"

HandlerFunctorBase* MemoryCreateObject2::CreateAnimationObjectDrawHandler()
{
    return new AnimationObjectDrawHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateAnimationObjectLoadHandler()
{
    return new AnimationObjectLoadHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateAnticipateAttackHandler()
{
    return new AnticipateAttackHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateArrowAttachHandler()
{
    return new ArrowAttachHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateArrowDetachHandler()
{
    return new ArrowDetachHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateArrowReleaseHandler()
{
    return new ArrowReleaseHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateAttackStopHandler()
{
    return new AttackStopHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateAttackWinEndHandler()
{
    return new AttackWinEndHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateAttackWinStartHandler()
{
    return new AttackWinStartHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateBedEnterHandler()
{
    return new BedEnterHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateBedFurnitureExitHandler()
{
    return new BedFurnitureExitHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateBowDrawnHandler()
{
    return new BowDrawnHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateBowReleaseHandler()
{
    return new BowReleaseHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateBowZoomStartHandler()
{
    return new BowZoomStartHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateBowZoomStopHandler()
{
    return new BowZoomStopHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateCameraOverrideStartHandler()
{
    return new CameraOverrideStartHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateCameraOverrideStopHandler()
{
    return new CameraOverrideStopHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateCameraShakeHandler()
{
    return new CameraShakeHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateChairEnterHandler()
{
    return new ChairEnterHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateChairFurnitureExitHandler()
{
    return new ChairFurnitureExitHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateDeathEmoteHandler()
{
    return new DeathEmoteHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateDeathStopHandler()
{
    return new DeathStopHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateDecapitateHandler()
{
    return new DecapitateHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateDisableCharacterBumperHandler()
{
    return new DisableCharacterBumperHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateDisableCharacterPitchHandler()
{
    return new DisableCharacterPitchHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateEnableCharacterBumperHandler()
{
    return new EnableCharacterBumperHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateEnableCharacterPitchHandler()
{
    return new EnableCharacterPitchHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateEndSummonAnimationHandler()
{
    return new EndSummonAnimationHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateExitCartBeginHandler()
{
    return new ExitCartBeginHandler();
}

HandlerFunctorBase* MemoryCreateObject2::CreateExitCartEndHandler()
{
    return new ExitCartEndHandler();
}
