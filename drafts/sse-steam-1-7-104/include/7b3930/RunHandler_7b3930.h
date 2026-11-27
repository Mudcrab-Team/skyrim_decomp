// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; represented declarations use the labelled source below.
// RunHandler, RunHandler::ProcessButton, ButtonEvent, ButtonEvent::value, ButtonEvent::heldDownSecs, PlayerControlsData, PlayerControlsData::running: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown: GUESS(low) STANDIN; unaccessed layout extents before named fields.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
#include <cstddef>
struct ButtonEvent {
    std::uint8_t unknown[0x28];
    float value;
    float heldDownSecs;
};
struct PlayerControlsData {
    std::uint8_t unknown[0x25];
    bool running;
};
static_assert(offsetof(ButtonEvent, value) == 0x28, "button value offset");
static_assert(offsetof(ButtonEvent, heldDownSecs) == 0x2c, "button duration offset");
static_assert(offsetof(PlayerControlsData, running) == 0x25, "running flag offset");
class RunHandler {
public:
    void ProcessButton(ButtonEvent* event, PlayerControlsData* data); // compared: 0x7b3930
};
