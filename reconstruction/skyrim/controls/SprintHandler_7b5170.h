// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original reconstruction; trimmed community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SprintHandler, InputEvent, QUserEvent, UserEvents, sprint, toggleRun, cursor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SprintHandler::Function7b5170, gUserEvents: GUESS(low); RVA name and singleton pointer view
#pragma once

#include <cstdint>
#include <cstddef>

// StringRef: GUESS(low) STANDIN; interned-string representation
struct StringRef { const char* data; };

class InputEvent
{
public:
    virtual ~InputEvent();
    virtual bool HasIDCode() const;
    virtual const StringRef& QUserEvent() const;
};

struct UserEvents
{
    std::uint8_t unknown00[0x88];
    StringRef sprint;
    std::uint8_t unknown90[0x28];
    StringRef toggleRun;
    std::uint8_t unknownc0[0xc0];
    StringRef cursor;
};
static_assert(offsetof(UserEvents, sprint) == 0x88, "sprint offset");
extern UserEvents* gUserEvents;

class SprintHandler
{
public:
    bool Function7b5170(InputEvent* event);  // compared: 0x7b5170; CanProcess candidate
};
