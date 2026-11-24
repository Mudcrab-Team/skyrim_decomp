// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// PathingRequest, BSPathingRequest: EXE_RTTI
// BSPathingRequest: STANDIN EXE_RTTI; only its out-of-line destructor is declared
#pragma once

class BSPathingRequest
{
public:
    BSPathingRequest();
    virtual ~BSPathingRequest();
};

class PathingRequest : public BSPathingRequest
{
public:
    PathingRequest();
    ~PathingRequest() override {}

    char unk08[0xF8];
};
static_assert(sizeof(PathingRequest) == 0x100, "PathingRequest size from the deleting destructor");
