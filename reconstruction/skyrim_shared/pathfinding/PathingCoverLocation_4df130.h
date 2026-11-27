// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// PathingCoverLocation: EXE_RTTI
// BSPathingLocation: EXE_RTTI STANDIN; only the members and destructors the function needs; the base sits after the vptr because it has none
#pragma once

class BSPathingLocation
{
public:
    ~BSPathingLocation();

    char unk00[0x60];
};

class PathingCoverLocation : public BSPathingLocation
{
public:
    PathingCoverLocation();
    virtual ~PathingCoverLocation() {}
};
static_assert(sizeof(PathingCoverLocation) == 0x68, "PathingCoverLocation size from the deleting destructor");
