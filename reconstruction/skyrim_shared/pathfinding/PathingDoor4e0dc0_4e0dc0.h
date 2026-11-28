// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// PathingDoor4e0dc0, PathingDoorBase4e0dc0, PathingSubObject4e0dc0, unk08, unk18, unk48: GUESS(low) STANDIN; community list calls 0x4e0dc0 BSPathingDoor::ctor, which does not match this destructor body
#pragma once

#include <cstdint>

class PathingSubObject4e0dc0
{
public:
    ~PathingSubObject4e0dc0();

    std::uint8_t unk00[0x30];  // 00
};
static_assert(sizeof(PathingSubObject4e0dc0) == 0x30, "PathingSubObject4e0dc0 size");

class PathingDoorBase4e0dc0
{
public:
    virtual ~PathingDoorBase4e0dc0() {}

    std::uint8_t unk08[0x10];  // 08
};
static_assert(sizeof(PathingDoorBase4e0dc0) == 0x18, "PathingDoorBase4e0dc0 size");

class PathingDoor4e0dc0 : public PathingDoorBase4e0dc0
{
public:
    ~PathingDoor4e0dc0() override;

    PathingSubObject4e0dc0 unk18;  // 18
    PathingSubObject4e0dc0 unk48;  // 48
};
static_assert(sizeof(PathingDoor4e0dc0) == 0x78, "PathingDoor4e0dc0 size");
