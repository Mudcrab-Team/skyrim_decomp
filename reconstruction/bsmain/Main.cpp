// Source exposure: mixed (pinned image listing and sibling hints).
// Code origin: existing sibling-adapted method plus original reconstruction of Function65b6a0.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/Main.cpp:137
// Adapted bodies: WorldRootCamera from fo4-private@1b765c70; Function65b6a0 original.
// 0x65c480 Main::WorldRootCamera
// 0x65b6a0 Main::Function65b6a0
#include "Main.h"

void* Main::WorldRootCamera() { return worldRoot->camera; }

bool Main::Function65b6a0() { return GetMainState()->flag11D != 0; }
