// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiIntegersExtraData, NiIntegersExtraData::dtor_deleting: CRASHLOGGER_PDB(59818@2026.10.24)
// NiExtraData, NiFree, size, data: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;
void NiFree(void* a_ptr);

class NiExtraData
{
public:
    virtual ~NiExtraData();

    std::uint8_t unk08[0x10];  // 08
};
static_assert(sizeof(NiExtraData) == 0x18, "NiExtraData size");

class NiIntegersExtraData : public NiExtraData
{
public:
    NiIntegersExtraData();
    ~NiIntegersExtraData() override;  // compared: 0xf12af0

    std::uint32_t size;  // 18
    std::int32_t* data;  // 20
};
static_assert(sizeof(NiIntegersExtraData) == 0x28, "NiIntegersExtraData size");
