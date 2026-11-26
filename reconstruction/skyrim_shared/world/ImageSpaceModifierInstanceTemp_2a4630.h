// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ImageSpaceModifierInstanceTemp, ImageSpaceModifierInstanceTemp::ctor: CRASHLOGGER_PDB(59818@2026.10.24); names only
// ImageSpaceModifierInstance, ImageSpaceModifierInstance::unk10, ImageSpaceModifierInstance::strength, ImageSpaceModifierInstance::target, ImageSpaceModifierInstance::age, ImageSpaceModifierInstance::flags, ImageSpaceModifierInstanceTemp::duration: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's layout, the constructor arguments are read from the listing
// ImageSpaceModifierInstance::Apply, ImageSpaceModifierInstance::PrintInfo: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared only so the vtable has the slots
// NiObject, NiAVObject, NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only what the constructor touches
// Adapted bodies: none. The origin check reports NiAVObject::IncRefCount as similar to a body cited below (f3_decomp@f5bac1b5, CC0-1.0), and the NiPointer constructor resembles the second cited line; ours are short forms written for this unit.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:46360
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00420000_o2.cpp:46366
// NiRefObject::m_uiRefCount, NiRefObject::IncRefCount: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declared on the stand-ins here, the count at 08 that the pointer copy increments
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiObject
{
public:
    NiObject();  // callee at 0xedcbc0, not compared here
    virtual ~NiObject();

    // volatile: the count is changed atomically with interlocked operations
    volatile long m_uiRefCount;  // 08
    std::uint32_t unk0C;
};

class NiAVObject : public NiObject
{
public:
    // hot path: the engine increments the count atomically, as NiRefObject::IncRefCount does
    void IncRefCount() { _InterlockedIncrement(&m_uiRefCount); }
};

template <class T>
class NiPointer
{
public:
    explicit NiPointer(T* a_object) : _ptr(a_object)
    {
        if (_ptr) {
            _ptr->IncRefCount();
        }
    }
    ~NiPointer();

    T* _ptr;
};

class ImageSpaceModifierInstance : public NiObject
{
public:
    ImageSpaceModifierInstance(float a_age, float a_strength, NiAVObject* a_target)
        : NiObject(), unk10(0), strength(a_strength), target(a_target), age(a_age), flags(0)
    {
    }
    ~ImageSpaceModifierInstance() override;
    virtual void Apply() = 0;
    virtual void PrintInfo(char* a_dstBuf) = 0;

    std::uint8_t unk10;           // 10
    float strength;               // 14
    NiPointer<NiAVObject> target; // 18
    float age;                    // 20
    std::uint32_t flags;          // 24
};
static_assert(sizeof(ImageSpaceModifierInstance) == 0x28, "layout");

class ImageSpaceModifierInstanceTemp : public ImageSpaceModifierInstance
{
public:
    ImageSpaceModifierInstanceTemp(float a_age, float a_strength, NiAVObject* a_target, float a_duration);  // compared: 0x2a4630
    ~ImageSpaceModifierInstanceTemp() override;
    void Apply() override;
    void PrintInfo(char* a_dstBuf) override;

    float duration;  // 28
    std::uint32_t unk2C;
};
static_assert(sizeof(ImageSpaceModifierInstanceTemp) == 0x30, "layout");
