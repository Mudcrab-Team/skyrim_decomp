// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// BSPathingDoor, Unk_02: CRASHLOGGER_PDB(59818@2026.10.24)
// PathingTarget3f0f70, Unk_01, Unk_03, Unk_04, unk08, unk58: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class PathingTarget3f0f70
{
public:
    virtual ~PathingTarget3f0f70();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04(PathingTarget3f0f70* previous);  // 20
};

class BSPathingDoor
{
public:
    virtual ~BSPathingDoor();
    virtual void Unk_01();
    virtual void Unk_02(PathingTarget3f0f70* next);

    std::uint8_t         unk08[0x50];  // 08
    PathingTarget3f0f70* unk58;        // 58
};
static_assert(sizeof(BSPathingDoor) == 0x60, "BSPathingDoor size");
