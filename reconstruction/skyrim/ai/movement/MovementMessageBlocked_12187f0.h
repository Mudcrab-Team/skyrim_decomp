// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// MovementMessageBlocked, MovementMessage: EXE_RTTI
// MovementMessage: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class MovementMessage
{
public:
    MovementMessage();
    virtual ~MovementMessage();
};

class MovementMessageBlocked : public MovementMessage
{
public:
    MovementMessageBlocked();
    ~MovementMessageBlocked() override {}

    char unk08[0x8];
};
static_assert(sizeof(MovementMessageBlocked) == 0x10, "MovementMessageBlocked size from the deleting destructor");
