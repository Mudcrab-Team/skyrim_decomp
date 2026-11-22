// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x7a5be0 MovementHandlerAgentSprintActionTrigger::Func4_1406FD2C0
// Adapted bodies: none
#include "MovementHandlerAgentSprintActionTrigger_7a5be0.h"

void MovementHandlerAgentSprintActionTrigger::Func4_1406FD2C0(IMovementControllerRegisterInterface* iface)
{
    pRegisterInterface = iface;
    pRegisterInterface->Register(IMovementSetSprinting::QClassType(), registrationSlot);
}
