// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementHandler, CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// InputEvent, UserEvents, BSFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// QUserEvent, singleton, data, unk00, forward, back, strafeLeft, strafeRight, move, Unk_01: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct BSFixedString
{
    const char* data;  // 00

    bool operator==(const BSFixedString& rhs) const { return data == rhs.data; }
};

class InputEvent
{
public:
    virtual ~InputEvent();
    virtual void                 Unk_01();
    virtual const BSFixedString& QUserEvent() const;  // 10
};

struct UserEvents
{
    static UserEvents* singleton;

    std::uint64_t unk00;        // 00
    BSFixedString forward;      // 08
    BSFixedString back;         // 10
    BSFixedString strafeLeft;   // 18
    BSFixedString strafeRight;  // 20
    BSFixedString move;         // 28
};

class MovementHandler
{
public:
    bool CanProcess(InputEvent* event);
};
