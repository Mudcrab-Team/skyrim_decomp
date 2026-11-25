// Source exposure: mixed (sibling source; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x7a5810 MovementHandlerAgentPlayerControlsActionTrigger::Deactivate
// Adapted bodies: MovementHandlerAgentPlayerControlsActionTrigger::Deactivate from the sibling source named in the header
#include "MovementHandlerAgentPlayerControlsActionTrigger_7a5810.h"

void MovementHandlerAgentPlayerControlsActionTrigger::Deactivate()
{
    std::uint32_t bits = BSUntypedPointerHandle::hNull.iBits;
    BSPointerHandle* handle = &MyHandle;
    if (MyHandle.iBits != BSUntypedPointerHandle::hNull.iBits) {
        if (PlayerControls::pInstance) {
            PlayerControls::pInstance->UnregisterActor(*handle);
            bits = BSUntypedPointerHandle::hNull.iBits;
        }
        handle->iBits = bits;
    }
}
