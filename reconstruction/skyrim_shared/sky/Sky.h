// Source exposure: mixed (Skyrim binary analysis, community declarations, fo4-private reconstruction).
// Origin: adapted from the cited anonymous permitted sibling body; partial Skyrim class view.
// Licence: fo4-private reused with author permission conditional on anonymity (awarebayes, 2026-11-14).
// Sky: SIBLING(fo4-private@1b765c70, author-permission)
// ReleaseWeatherOverride: SIBLING(fo4-private@1b765c70, author-permission)
// Padding and incomplete declarations: STANDIN GUESS(low); no complete-layout or behaviour claim.
// Sibling source: fo4-private@1b765c70 src/Shared/Sky/Sky.cpp:129
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include <cstddef>
#include <cstring>
class TESWeather;
class Sky {public:
void ReleaseWeatherOverride();
std::uint8_t pad[0x60]; TESWeather* pOverrideWeather;
std::uint8_t pad68[0x1dc-0x68]; unsigned int uiFlags;
};
