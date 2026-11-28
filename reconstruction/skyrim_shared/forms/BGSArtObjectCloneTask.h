// Source exposure: mixed (pinned image listing; community source; CrashLogger PDB names).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiPointer25d4c0::operator=, NiRefObject25d4c0::IncRefCount and DecRefCount, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSArtObjectCloneTask: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject25d4c0, NiPointer25d4c0, BGSArtObjectCloneTask::Function25d4c0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiRefObject25d4c0
{
public:
    virtual ~NiRefObject25d4c0();
    virtual void DeleteThis();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual NiRefObject25d4c0* CloneObject(void* a_unk1, void* a_unk2);

    void IncRefCount()
    {
        // thread-safe reference count increment
        _InterlockedIncrement(&refCount);
    }

    void DecRefCount()
    {
        // thread-safe reference count decrement
        if (_InterlockedDecrement(&refCount) == 0) {
            DeleteThis();
        }
    }

    long refCount;  // 0x08
};

template <class T>
class NiPointer25d4c0
{
public:
    NiPointer25d4c0& operator=(T* a_rhs)
    {
        T* old = ptr;
        if (old != a_rhs) {
            if (a_rhs) {
                a_rhs->IncRefCount();
            }
            ptr = a_rhs;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* ptr;
};

class BGSArtObjectCloneTask
{
public:
    bool Function25d4c0();

    std::uint8_t unk00[0x78];                   // 0x00
    NiRefObject25d4c0* sourceObject;            // 0x78
    NiPointer25d4c0<NiRefObject25d4c0> cloned;  // 0x80
};

static_assert(offsetof(NiRefObject25d4c0, refCount) == 0x08, "refCount offset");
static_assert(offsetof(BGSArtObjectCloneTask, sourceObject) == 0x78, "sourceObject offset");
static_assert(offsetof(BGSArtObjectCloneTask, cloned) == 0x80, "cloned offset");
