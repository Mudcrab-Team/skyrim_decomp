// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xab7940
// Adapted bodies: none.
// ByteStreamAb7940, StreamWriterAb7940: GUESS(low) STANDIN
#pragma once

#include <cstdint>

class ByteStreamAb7940 {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Write(const void* a_data, std::uint32_t a_size);
};

struct StreamWriterAb7940 {
    std::uint64_t reserved00;
    std::uint64_t reserved08;
    ByteStreamAb7940* stream;

    void WriteByte(std::uint8_t a_value);
};
