// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// BGSSaveFormBuffer, BSTSmallArray: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SaveState121d140, Func1, SaveFloat, SaveUInt32, SaveFormData, Unk_02..Unk_0A, Unk40, Entry, SaveGame, Write, data, capacity, ptr, storage, entries, count, unk00, unk04, unk40, unkA4, unkA8, unkB0, unkB4, unkB8: GUESS(low) STANDIN
// ImageSpaceEffectGetHit::Func1: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); that name does not fit the save-buffer calls or the layout used here, so the class is a stand-in.
#pragma once

#include <cstdint>
#include <cstddef>

class BGSSaveFormBuffer
{
public:
    virtual ~BGSSaveFormBuffer();
    virtual void SaveFloat(float a_value);
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void SaveUInt32(std::uint32_t a_value);
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void SaveFormData(void* a_data);
};

class Unk40
{
public:
    void SaveGame(BGSSaveFormBuffer* a_buf);  // callee at 0x12512b0, not compared
    std::uint8_t unk00[0x30];
};
static_assert(sizeof(Unk40) == 0x30, "Unk40 size");

class Entry
{
public:
    void Write(BGSSaveFormBuffer* a_buf);  // callee at 0x11fe750, not compared
    std::uint8_t unk00[0x24];
};
static_assert(sizeof(Entry) == 0x24, "Entry size");

template <class T>
class BSTSmallArray
{
public:
    T* data()
    {
        return capacity < 0 ? reinterpret_cast<T*>(&storage) : ptr;
    }

    std::int32_t capacity;  // 00
    std::uint32_t unk04;    // 04
    union
    {
        T* ptr;
        std::uint8_t storage[0x24];
    };                      // 08
};

class SaveState121d140
{
public:
    void Func1(BGSSaveFormBuffer* a_buf);  // compared: 0x121d140

    std::uint8_t unk00[0x40];       // 00
    Unk40 unk40;                    // 40
    BSTSmallArray<Entry> entries;   // 70
    std::uint32_t count;            // A0
    std::uint32_t unkA4;            // A4
    std::uint64_t unkA8;            // A8
    float unkB0;                    // B0
    float unkB4;                    // B4
    std::uint32_t unkB8;            // B8
};
static_assert(offsetof(SaveState121d140, unk40) == 0x40, "unk40 offset");
static_assert(offsetof(SaveState121d140, entries) == 0x70, "entries offset");
static_assert(offsetof(SaveState121d140, count) == 0xA0, "count offset");
static_assert(offsetof(SaveState121d140, unkA8) == 0xA8, "unkA8 offset");
static_assert(offsetof(SaveState121d140, unkB0) == 0xB0, "unkB0 offset");
static_assert(offsetof(SaveState121d140, unkB4) == 0xB4, "unkB4 offset");
static_assert(offsetof(SaveState121d140, unkB8) == 0xB8, "unkB8 offset");
