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
// 0x7d61c0 MemoryCreateObject4::CreateNPCAttachHandler
// 0x7d6220 MemoryCreateObject4::CreateNPCDetachHandler
// 0x7d6280 MemoryCreateObject4::CreatePairedStopHandler
// 0x7d62e0 MemoryCreateObject4::CreatePickNewIdleHandler
// 0x7d6340 MemoryCreateObject4::CreatePitchOverrideEndHandler
// 0x7d63a0 MemoryCreateObject4::CreatePitchOverrideStartHandler
// 0x7d6400 MemoryCreateObject4::CreatePlayerBedEnterHandler
// 0x7d6460 MemoryCreateObject4::CreatePlayerChairEnterHandler
// 0x7d64c0 MemoryCreateObject4::CreatePlayerFurnitureExitHandler
// 0x7d6520 MemoryCreateObject4::CreateRagdollStartHandler
// 0x7d6580 MemoryCreateObject4::CreateRecoilStopHandler
// 0x7d65e0 MemoryCreateObject4::CreateRemoveRagdollHandler
// 0x7d6640 MemoryCreateObject4::CreateRightHandSpellCastHandler
// 0x7d66a0 MemoryCreateObject4::CreateRightHandSpellFireHandler
// 0x7d6700 MemoryCreateObject4::CreateRightHandWeaponDrawHandler
// 0x7d6760 MemoryCreateObject4::CreateRightHandWeaponSheatheHandler
// 0x7d67c0 MemoryCreateObject4::CreateStaggeredStopHandler
// 0x7d6820 MemoryCreateObject4::CreateStopMountCameraHandler
// 0x7d6880 MemoryCreateObject4::CreateVampireFeedEndHandler
// 0x7d68e0 MemoryCreateObject4::CreateVoiceSpellCastHandler
// 0x7d6940 MemoryCreateObject4::CreateVoiceSpellFireHandler
// 0x7d69a0 MemoryCreateObject4::CreateWeaponBeginDrawRightHandler
// 0x7d6a00 MemoryCreateObject4::CreateWeaponBeginSheatheRightHandler
// 0x7d6a60 MemoryCreateObject4::CreateWeaponLeftSwingHandler
// 0x7d6ac0 MemoryCreateObject4::CreateWeaponRightSwingHandler
// 0x7d6b20 MemoryCreateObject4::CreateZeroPitchHandler
// 0x98ccf0 MemoryCreateObject4::CreateConsoleData
// 0x98cfa0 MemoryCreateObject4::CreateFaderData
// 0x98d1f0 MemoryCreateObject4::CreateRefHandleUIData
// 0x98d310 MemoryCreateObject4::CreateTESFormUIData
#include "MemoryCreateObject4.h"

HandlerFunctorBase* MemoryCreateObject4::CreateNPCAttachHandler()
{
    return new NPCAttachHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateNPCDetachHandler()
{
    return new NPCDetachHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePairedStopHandler()
{
    return new PairedStopHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePickNewIdleHandler()
{
    return new PickNewIdleHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePitchOverrideEndHandler()
{
    return new PitchOverrideEndHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePitchOverrideStartHandler()
{
    return new PitchOverrideStartHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePlayerBedEnterHandler()
{
    return new PlayerBedEnterHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePlayerChairEnterHandler()
{
    return new PlayerChairEnterHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreatePlayerFurnitureExitHandler()
{
    return new PlayerFurnitureExitHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRagdollStartHandler()
{
    return new RagdollStartHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRecoilStopHandler()
{
    return new RecoilStopHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRemoveRagdollHandler()
{
    return new RemoveRagdollHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRightHandSpellCastHandler()
{
    return new RightHandSpellCastHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRightHandSpellFireHandler()
{
    return new RightHandSpellFireHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRightHandWeaponDrawHandler()
{
    return new RightHandWeaponDrawHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateRightHandWeaponSheatheHandler()
{
    return new RightHandWeaponSheatheHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateStaggeredStopHandler()
{
    return new StaggeredStopHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateStopMountCameraHandler()
{
    return new StopMountCameraHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateVampireFeedEndHandler()
{
    return new VampireFeedEndHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateVoiceSpellCastHandler()
{
    return new VoiceSpellCastHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateVoiceSpellFireHandler()
{
    return new VoiceSpellFireHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateWeaponBeginDrawRightHandler()
{
    return new WeaponBeginDrawRightHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateWeaponBeginSheatheRightHandler()
{
    return new WeaponBeginSheatheRightHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateWeaponLeftSwingHandler()
{
    return new WeaponLeftSwingHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateWeaponRightSwingHandler()
{
    return new WeaponRightSwingHandler();
}

HandlerFunctorBase* MemoryCreateObject4::CreateZeroPitchHandler()
{
    return new ZeroPitchHandler();
}

// BSTDerivedCreator<ConsoleData, IUIMessageData>::Create; returns UIMessageDataBase* (CrashLogger PDB prototype lists void (QueuedPromoteReferencesTask*)).
UIMessageDataBase* MemoryCreateObject4::CreateConsoleData()
{
    return new ConsoleData();
}

// BSTDerivedCreator<FaderData, IUIMessageData>::Create; returns UIMessageDataBase* (CrashLogger PDB prototype lists IMemoryHeap*(void)).
UIMessageDataBase* MemoryCreateObject4::CreateFaderData()
{
    return new FaderData();
}

// BSTDerivedCreator<RefHandleUIData, IUIMessageData>::Create; returns UIMessageDataBase* (CrashLogger PDB prototype lists IMemoryHeap*(void)).
UIMessageDataBase* MemoryCreateObject4::CreateRefHandleUIData()
{
    return new RefHandleUIData();
}

// BSTDerivedCreator<TESFormUIData, IUIMessageData>::Create; returns UIMessageDataBase* (CrashLogger PDB prototype lists IMemoryHeap*(void)).
UIMessageDataBase* MemoryCreateObject4::CreateTESFormUIData()
{
    return new TESFormUIData();
}
