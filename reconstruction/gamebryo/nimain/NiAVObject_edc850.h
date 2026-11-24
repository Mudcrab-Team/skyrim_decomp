// Source exposure: mixed (community and sibling declarations, pinned image listing).
// Code origin: The class views follow the pinned image and labelled types. Cloning-process initialization follows the project's NiAVObject reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiAVObject, CreateClone, ProcessClone, cloneMap, processMap, copyType, appendChar, unk68, NiPoint3, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::Clone: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence) COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiCloningProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// CleanupProcessMap, CleanupCloneMap: GUESS(low)
// CloneHashMap, _pad00, _pad08, _capacity, _free, _good, _sentinel, _pad20, _entries: GUESS(low)
// kDefaultCopyType, kDefaultAppendChar, kCloneMapSentinel, kProcessMapSentinel, unk00 through unk1C: GUESS(low)
// Clone: OBSERVED; this stand-in keeps the inventory owner and calls the NiObject virtuals
// Adapted bodies: NiAVObject::Clone follows momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a40000_o2.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a40000_o2.cpp:3206
#pragma once

#include <cstdint>

class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

class CloneHashMap
{
public:
    std::uint64_t _pad00;
    std::uint32_t _pad08;
    std::uint32_t _capacity;
    std::uint32_t _free;
    std::uint32_t _good;
    const void* _sentinel;
    std::uint64_t _pad20;
    void* _entries;
};

extern const std::uint32_t kDefaultCopyType;
extern const char kDefaultAppendChar;
extern const std::uint8_t kCloneMapSentinel;
extern const std::uint8_t kProcessMapSentinel;
void CleanupProcessMap(std::uint32_t* map) noexcept;
void CleanupCloneMap(std::uint32_t* map) noexcept;

class NiCloningProcess
{
public:
    NiCloningProcess()
    {
        cloneMap._capacity = 0;
        cloneMap._free = 0;
        cloneMap._good = 0;
        cloneMap._sentinel = &kCloneMapSentinel;
        cloneMap._entries = nullptr;
        processMap._capacity = 0;
        processMap._free = 0;
        processMap._good = 0;
        processMap._sentinel = &kProcessMapSentinel;
        processMap._entries = nullptr;
        copyType = kDefaultCopyType;
        appendChar = kDefaultAppendChar;
        unk68.z = 1.0f;
        unk68.y = 1.0f;
        unk68.x = 1.0f;
    }

    ~NiCloningProcess()
    {
        CleanupProcessMap(&processMap._pad08);
        CleanupCloneMap(&cloneMap._pad08);
    }

    CloneHashMap cloneMap;
    CloneHashMap processMap;
    std::uint32_t copyType;
    char appendChar;
    NiPoint3 unk68;
};
static_assert(sizeof(NiCloningProcess) == 0x78, "NiCloningProcess size");

class NiObject
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual NiObject* CreateClone(NiCloningProcess& cloning);
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void ProcessClone(NiCloningProcess& cloning);
};

class NiAVObject : public NiObject
{
public:
    NiAVObject* Clone();
};
