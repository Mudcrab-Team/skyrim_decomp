// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x7b3270 LookHandler::ProcessMouseMove
#include "LookHandler_7b3270.h"

// Convert integer mouse deltas to look input floats, inverting the vertical axis.
void LookHandler::ProcessMouseMove(MouseMoveEvent* a_event, PlayerControlsData* a_data)
{
    a_data->lookX = static_cast<float>(a_event->mouseInputX);
    a_data->lookY = -static_cast<float>(a_event->mouseInputY);
}
