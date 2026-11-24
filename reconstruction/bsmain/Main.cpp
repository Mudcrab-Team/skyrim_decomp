// Source exposure: mixed (pinned image listing and sibling hints).
// Code origin: existing sibling-adapted method plus original reconstruction of Function65b6a0.; written for this reconstruction from the listing; names from the header (guessed, low confidence).
// Sibling source: fo4-private@1b765c70 src/Game/Misc/Main.cpp:137
// Adapted bodies: WorldRootCamera from fo4-private@1b765c70; Function65b6a0 original.
// 0x65c480 Main::WorldRootCamera
// 0x65b6a0 Main::Function65b6a0
// SPDX-License-Identifier: CC0-1.0
// 0x65c460 Main::Function65c460
// 0x65c8f0 Main::Function65c8f0
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "Main.h"

void* Main::WorldRootCamera() { return worldRoot->camera; }

bool Main::Function65b6a0() { return GetMainState()->flag11D != 0; }

static bool g_mainFlag;
struct MainSingleton { std::uint8_t pad[0x30190]; void* value; };
static MainSingleton** g_mainSingletonRef;

void Main::Function65c460() { g_mainFlag = false; }

void* Main::Function65c8f0() { return (*g_mainSingletonRef)->value; }
