// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original; declarations reduced from pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AutoMoveHandler, CanProcess, InputEvent, HasIDCode, QUserEvent, BSFixedString, UserEvents, autoMove, BSFixedString::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InputEvent, BSFixedString, UserEvents: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// reserved, userEvents: GUESS(low); minimal string storage, unused span and singleton binding.
// 0x7b4ee0 AutoMoveHandler::CanProcess
#pragma once
#include <cstddef>
#include <cstdint>

struct BSFixedString
{
    const char* data;
};
class InputEvent
{
public:
    virtual ~InputEvent();
    virtual bool HasIDCode() const;
    virtual const BSFixedString& QUserEvent() const;
};
struct UserEvents
{
    std::uint8_t reserved[0xC0];
    BSFixedString autoMove;
};
static_assert(offsetof(UserEvents, autoMove) == 0xC0, "auto-move name offset");
extern UserEvents* userEvents;
class AutoMoveHandler
{
public:
    bool CanProcess(InputEvent* a_event);
};
