// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// MovementHandlerAgentSprintActionTrigger::Func4_1406FD2C0: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementHandlerAgentSprintActionTrigger::pRegisterInterface: SYMBOLS(fo4-pdb); FO4 gives the offset 0x30 and the type name IMovementControllerRegisterInterface
// IMovementControllerRegisterInterface: SYMBOLS(fo4-pdb)
// IMovementControllerRegisterInterface::Register, MovementHandlerAgentSprintActionTrigger::registrationSlot: GUESS(low)
// IMovementSetSprinting::QClassType: SIBLING(fo4-private@1b765c70, author-permission); the name is the pack's callee name, the signature is read from the listing
#pragma once

struct IMovementControllerRegisterInterface
{
    virtual void unk00();
    virtual void Register(const void* type, void* slot);
};

struct IMovementSetSprinting
{
    static const void* QClassType();
};

class MovementHandlerAgentSprintActionTrigger
{
public:
    virtual void Func4_1406FD2C0(IMovementControllerRegisterInterface* iface);

    unsigned char pad08[0x18];
    unsigned char registrationSlot[0x10];
    IMovementControllerRegisterInterface* pRegisterInterface;
};
