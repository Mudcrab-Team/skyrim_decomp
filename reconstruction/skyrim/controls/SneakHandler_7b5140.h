// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; naming and represented declarations use the sources below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SneakHandler, SneakHandler::CanProcess, InputEvent, InputEvent::HasIDCode, InputEvent::QUserEvent, UserEvents, UserEvents::run, UserEvents::sneak: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSFixedString, BSFixedString::_data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_userEvents: OBSERVED; singleton pointer reference in the pinned target.
// unknown, unknown98: GUESS(low) STANDIN; unaccessed layout extent before the declared field.
#pragma once
#include <cstdint>
#include <cstddef>

struct BSFixedString { const char* _data; };
class InputEvent {
public:
    virtual ~InputEvent();
    virtual bool HasIDCode() const;
    virtual const BSFixedString& QUserEvent() const;
};
struct UserEvents {
    std::uint8_t unknown[0x90];
    BSFixedString sneak;
    std::uint8_t unknown98[0x18];
    BSFixedString run;
};
static_assert(offsetof(UserEvents, sneak) == 0x90, "observed sneak field offset");
static_assert(offsetof(UserEvents, run) == 0xB0, "observed run field offset");
extern UserEvents* g_userEvents;
class SneakHandler {
public:
    bool CanProcess(InputEvent* event);  // compared: 0x7b5140
};
