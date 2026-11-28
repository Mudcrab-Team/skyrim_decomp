// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x122cef0 MovementHandlerAgentLargeDeltaIdle::Func6_141117470
#include "MovementHandlerAgentLargeDeltaIdle_122cef0.h"

// Clear the large-delta idle state on the queried interface when active.
void MovementHandlerAgentLargeDeltaIdle::Func6_141117470()
{
    if (state == 1) {
        if (holder != nullptr) {
            LargeDeltaInterface* iface = holder->QueryInterface(gLargeDeltaInterfaceName);
            if (iface != nullptr) {
                iface->ClearIdle();
            }
        }
        state = 0;
    }
}
