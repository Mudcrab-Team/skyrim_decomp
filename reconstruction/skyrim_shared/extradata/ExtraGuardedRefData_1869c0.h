// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ExtraGuardedRefData, ExtraGuardedRefData::Load, ExtraGuardedRefData::refId, ExtraGuardedRefData::value, ExtraGuardedRefData::flag: GUESS(low)
// BGSLoadGameBuffer: GUESS(low); stand-in class
// BGSLoadGameBuffer::ReadFormID: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission); signature read from the pinned image
// BGSLoadGameBuffer::LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares (data, offset, size), the image passes (destination, size, count)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSLoadGameBuffer
{
public:
    void ReadFormID(std::uint32_t* formId);
    void LoadDataEndian(void* dst, std::uint32_t size, std::uint32_t count);
};

class ExtraGuardedRefData
{
public:
    void Load(BGSLoadGameBuffer* buffer);  // compared: 0x1869c0

    std::uint32_t refId;  // 0x00
    std::uint32_t value;  // 0x04
    std::uint8_t flag;    // 0x08
};
