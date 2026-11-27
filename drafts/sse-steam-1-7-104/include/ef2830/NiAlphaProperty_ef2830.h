// Exposure detail: (community names; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// NiAlphaProperty, NiAlphaProperty::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiProperty, NiProperty::LoadBinary, NiStream, NiBinaryStream: GUESS(low)
// ReadComponents, vtable: STANDIN GUESS(low)
// flags, alphaTestRef, position, input, baseStorage, streamStorage: OBSERVED

#pragma once
#include <cstdint>
#include <cstddef>
class NiBinaryStream {
public:
    using ReadFn = std::uint32_t (*)(NiBinaryStream*, void*, std::uint32_t,
        std::uint32_t*, std::uint32_t);
    void* vtable;
    std::uint32_t position;
    ReadFn ReadComponents;
    void Read(void* data, std::uint32_t size, std::uint32_t* sizes, std::uint32_t count) {
        position += ReadComponents(this, data, size, sizes, count);
    }
};
class NiStream {
public:
    std::uint8_t streamStorage[0x298];
    NiBinaryStream* input;
};
class NiProperty {
public:
    void LoadBinary(NiStream& stream);
    std::uint8_t baseStorage[0x30];
};
class NiAlphaProperty : public NiProperty {
public:
    void LoadBinary(NiStream& stream);
    std::uint16_t flags;
    std::uint8_t alphaTestRef;
};
static_assert(offsetof(NiAlphaProperty, flags) == 0x30, "flags offset");
static_assert(offsetof(NiAlphaProperty, alphaTestRef) == 0x32, "alpha reference offset");
