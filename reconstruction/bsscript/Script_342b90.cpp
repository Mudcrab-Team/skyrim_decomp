// Source exposure: mixed (community declarations; permitted sibling game code; pinned image).
// Code origin: adapted from the permitted FNV game-code initializer to the observed target layout
// SPDX-License-Identifier: CC0-1.0
// 0x342b90 Script::InitializeData
// Adapted bodies: Script::InitializeData, from Script::InitializeComponent in the cited sibling.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesscript.cpp:372
// InitializeComponent: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
#include "Script_342b90.h"
#include <cstring>

void Script::InitializeData()
{
    std::memset(header, 0, sizeof(header));
    data = nullptr;
    text = nullptr;
    Script_tls_0x600 = false;
    parentQuest = nullptr;
    profilerTimer = 0.0f;
    questScriptDelay = 0.0f;
    questScriptGetSecondsBuffer = 0.0f;
    formType = 19;
}
