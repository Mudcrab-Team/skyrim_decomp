// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// DirectionHandler, CanProcess: CRASHLOGGER_PDB(59818@2026.10.24)
// InputEvent, UserEvents, BSFixedString, QUserEvent: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// data, up, down, left, right, look, singleton, unk00, unk158, Unk_01: GUESS(low)
#pragma once

#include <cstdint>

class BSFixedString
{
public:
    bool operator==(const BSFixedString& other) const
    {
        return data == other.data;
    }

    const char* data;  // 00
};

class InputEvent
{
public:
    virtual ~InputEvent();
    virtual bool                 Unk_01();
    virtual const BSFixedString& QUserEvent() const;  // 10
};

class UserEvents
{
public:
    static UserEvents* singleton;

    std::uint8_t  unk00[0x138];   // 000
    BSFixedString up;             // 138
    BSFixedString down;           // 140
    BSFixedString left;           // 148
    BSFixedString right;          // 150
    std::uint8_t  unk158[0xA8];   // 158
    BSFixedString look;           // 200
};

class DirectionHandler
{
public:
    virtual ~DirectionHandler();
    virtual bool CanProcess(InputEvent* event);
};
