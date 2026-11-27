// Source exposure: mixed (community declarations; permitted sibling game code; pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial layout from the community header and observed accesses.
// Script, InitializeData, header, data, text, parentQuest, profilerTimer, questScriptDelay, questScriptGetSecondsBuffer, formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// prefix, reserved1B, Script_tls_0x600: STANDIN GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
__declspec(thread) extern bool Script_tls_0x600;
class Script
{
public:
    void InitializeData();
    std::uint8_t prefix[0x1A];
    std::uint8_t formType;
    std::uint8_t reserved1B[5];
    std::uint8_t header[0x14];
    char* text;
    void* data;
    float profilerTimer;
    float questScriptDelay;
    float questScriptGetSecondsBuffer;
    void* parentQuest;
};
static_assert(offsetof(Script, header) == 0x20, "community header offset");
static_assert(offsetof(Script, parentQuest) == 0x58, "community quest offset");
