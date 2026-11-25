// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x9f0650 ??_GAnimEventSink@DebugTextAnimation@@UEAAPEAXI@Z
// 0x9f0650 DebugTextAnimation::AnimEventSink::`scalar deleting destructor'
// Adapted bodies: BSTEventSink::~BSTEventSink from fo4-private@1b765c70 src/BSCore/BSTEvent.h:23
#include "DebugTextAnimation_9f0650.h"

// The constructor is what makes the compiler emit the vftable and the deleting destructor in this unit.
DebugTextAnimation::AnimEventSink::AnimEventSink()
{
}
