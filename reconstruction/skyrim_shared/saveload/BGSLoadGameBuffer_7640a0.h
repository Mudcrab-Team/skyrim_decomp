// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BGSLoadGameBuffer: EXE_RTTI
// BGSLoadGameBuffer::sub_1406BB790: CRASHLOGGER_PDB(59818@2026.10.24)
// BGSLoadGameBuffer::LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadGameBuffer::GetVersion, g_saveState48, g_saveFlag46, g_saveFlag47A, g_saveFlag47B, g_saveState47C: GUESS(low); virtual slot and globals observed in listing
#pragma once

#include <cstdint>

extern std::uint32_t g_saveState48;
extern std::uint8_t  g_saveFlag46;
extern std::uint8_t  g_saveFlag47A;
extern std::uint8_t  g_saveFlag47B;
extern std::uint32_t g_saveState47C;

class BGSLoadGameBuffer
{
public:
    virtual ~BGSLoadGameBuffer();           // 00
    virtual std::uint8_t GetVersion() const; // 01

    void         LoadDataEndian(void* a_data, std::uint32_t a_offset, std::uint32_t a_size);
    std::uint8_t ReadByte()
    {
        std::uint8_t value;
        LoadDataEndian(&value, 1, 1);
        return value;
    }
    void sub_1406BB790();
};
