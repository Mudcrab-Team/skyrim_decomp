// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Writer_11b8320, Sub_11b8320, Data_11b8320, Function11b8320, Slot0, WriteFloat, Slot2, Slot3, WriteUInt32, Slot5, WriteUInt16, Slot7, WriteUInt8, Slot9, Slot10, WriteId, GetTypeId, Write, x, y, z, idPtr, unk18, sub, u28, u2a, u2b, value, data, writer: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Writer_11b8320
{
    virtual void Slot0();
    virtual void WriteFloat(float value);
    virtual void Slot2();
    virtual void Slot3();
    virtual void WriteUInt32(std::uint32_t value);
    virtual void Slot5();
    virtual void WriteUInt16(std::uint16_t value);
    virtual void Slot7();
    virtual void WriteUInt8(std::uint8_t value);
    virtual void Slot9();
    virtual void Slot10();
    virtual void WriteId(std::uint32_t value);
};

struct Sub_11b8320
{
    virtual void Slot0();
    virtual std::uint32_t GetTypeId();
    virtual void Write(Writer_11b8320* writer);
};

struct Data_11b8320
{
    float x;                        // 0x00
    float y;                        // 0x04
    float z;                        // 0x08
    const std::uint32_t* idPtr;     // 0x10
    std::uint64_t unk18;            // 0x18
    Sub_11b8320* sub;               // 0x20
    std::uint16_t u28;              // 0x28
    std::uint8_t u2a;               // 0x2A
    std::uint8_t u2b;               // 0x2B
};
static_assert(offsetof(Data_11b8320, idPtr) == 0x10, "idPtr offset");
static_assert(offsetof(Data_11b8320, sub) == 0x20, "sub offset");
static_assert(offsetof(Data_11b8320, u28) == 0x28, "u28 offset");
static_assert(offsetof(Data_11b8320, u2a) == 0x2A, "u2a offset");
static_assert(offsetof(Data_11b8320, u2b) == 0x2B, "u2b offset");

void Function11b8320(const Data_11b8320* data, Writer_11b8320* writer);
