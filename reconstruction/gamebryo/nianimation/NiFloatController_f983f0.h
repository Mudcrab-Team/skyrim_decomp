// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; fresh draft from the authorized target pack and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiFloatController::Functionf983f0: GUESS(low); address-based placeholder
// NiFloatData, NiFloatKey, NiFloatData::numKeys, NiFloatData::keys, NiFloatData::type, NiFloatData::keySize: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiFloatController::data: GUESS(low); observed pointer at offset 0x50
#pragma once

#include <cstddef>
#include <cstdint>

class NiFloatKey;

class NiFloatData
{
public:
    std::uint8_t unobserved00[0x10];
    std::uint32_t numKeys;
    std::uint32_t unobserved14;
    NiFloatKey* keys;
    std::uint32_t type;
    std::uint8_t keySize;
};
static_assert(offsetof(NiFloatData, numKeys) == 0x10, "numKeys offset");
static_assert(offsetof(NiFloatData, keys) == 0x18, "keys offset");
static_assert(offsetof(NiFloatData, type) == 0x20, "type offset");
static_assert(offsetof(NiFloatData, keySize) == 0x24, "keySize offset");

class NiFloatController
{
public:
    NiFloatKey* Functionf983f0(std::uint32_t& count, std::uint32_t& keyType, std::uint8_t& stride);

    std::uint8_t unobserved00[0x50];
    NiFloatData* data;
};
static_assert(offsetof(NiFloatController, data) == 0x50, "data offset");
