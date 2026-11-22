// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled in the header
// 0x7a3e70 MovementHandlerAgentPlayerControls::Func10_1406FB930
// Adapted bodies: none
#include "MovementHandlerAgentPlayerControls_7a3e70.h"

// Drops the registered interface and frees the owned control state.
void MovementHandlerAgentPlayerControls::Func10_1406FB930()
{
    if (registerInterface) {
        registerInterface->Unregister(&g_registerKey);
        registerInterface = nullptr;
    }
    if (state) {
        delete state;
        state = nullptr;
    }
}
