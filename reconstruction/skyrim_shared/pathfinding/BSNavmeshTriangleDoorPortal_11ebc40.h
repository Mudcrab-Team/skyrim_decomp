// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// BSNavmeshTriangleDoorPortal, BSNavmeshTriangleDoorPortal::Write, door, owningTriangleIndex, BSPathingDoor: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPathingStreamWrite, WriteUInt32, WriteUInt16, GetType, Write: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSPathingStreamWrite
{
public:
    virtual ~BSPathingStreamWrite() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void WriteUInt32(std::uint32_t a_value) = 0;  // slot 04 (+0x20)
    virtual void Slot05() = 0;
    virtual void WriteUInt16(std::uint16_t a_value) = 0;  // slot 06 (+0x30)
};

class BSPathingDoor
{
public:
    virtual ~BSPathingDoor() = 0;
    virtual std::uint32_t GetType() const = 0;                  // slot 01 (+0x08)
    virtual void Slot02() = 0;
    virtual void Write(BSPathingStreamWrite* a_stream) = 0;     // slot 03 (+0x18)
};

class BSNavmeshTriangleDoorPortal
{
public:
    void Write(BSPathingStreamWrite* a_stream);  // compared: 0x11ebc40

    BSPathingDoor* door;                 // 00
    std::uint16_t owningTriangleIndex;   // 08
    std::uint16_t reserved0A;            // 0A
    std::uint32_t reserved0C;            // 0C
};
static_assert(sizeof(BSNavmeshTriangleDoorPortal) == 0x10, "BSNavmeshTriangleDoorPortal size");
