// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// RVA 0x12db40, 62 bytes: UI_Text3 scalar deleting destructor; the inline destructor chains to the out-of-line UI_Text destructor.
// Code origin: original reconstruction from the pinned image listing
// Adapted bodies: none
// CI hash: 0x12db40 ??_GUI_Text3@@UEAAPEAXI@Z
#include "UI_Text3_12db40.h"

// The constructor emits the vftable and with it the deleting destructor in this object.
UI_Text3::UI_Text3()
{
}
