// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiObject::IncRefCount as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niscreentexture.cpp:538
// SPDX-License-Identifier: CC0-1.0
// NiObject, NiPointer, NiStream, NiTimeController, BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSProceduralLightningController::LinkObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::DeleteThis, NiObject::IncRefCount, NiObject::DecRefCount, NiObject::refCount, NiObject::unk0C, NiPointer::_ptr, NiStream::ReadLinkID, NiTimeController::LinkObject, NiTimeController::Unk_00, NiTimeController::Unk_01, NiTimeController::Unk_02, NiTimeController::Unk_03, NiTimeController::Unk_04, NiTimeController::Unk_05, NiTimeController::Unk_06, NiTimeController::Unk_07, NiTimeController::Unk_08, NiTimeController::Unk_09, NiTimeController::Unk_0A, NiTimeController::Unk_0B, NiTimeController::Unk_0C, NiTimeController::Unk_0D, NiTimeController::Unk_0E, NiTimeController::Unk_0F, NiTimeController::Unk_10, NiTimeController::Unk_11, NiTimeController::Unk_12, NiTimeController::Unk_13, NiTimeController::Unk_14, NiTimeController::Unk_15, NiTimeController::Unk_16, NiTimeController::Unk_17, NiTimeController::Unk_18, NiTimeController::Unk_19, NiTimeController::Unk_1A, NiTimeController::Unk_1B, NiTimeController::Unk_1C, NiTimeController::Unk_1D, NiTimeController::Unk_1E, NiTimeController::Unk_1F, NiTimeController::Unk_20, NiTimeController::Unk_21, NiTimeController::Unk_22, NiTimeController::Unk_23, NiTimeController::Unk_24, NiTimeController::Unk_25, NiTimeController::Unk_26, NiTimeController::Unk_27, NiTimeController::Unk_28, NiTimeController::Unk_29, NiTimeController::Unk_2A, NiTimeController::Unk_2B, NiTimeController::Unk_2C, NiTimeController::Unk_2D, NiTimeController::Unk_2E, NiTimeController::Unk_2F, NiTimeController::Unk_30, NiTimeController::Unk_31, NiTimeController::Unk_32, NiTimeController::Unk_33, NiTimeController::SetInterpolator, NiTimeController::unk08, BSProceduralLightningController::unk48, BSProceduralLightningController::targetObject: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include <intrin.h>

class NiObject
{
public:
    virtual ~NiObject();
    virtual void DeleteThis();

    void IncRefCount()
    {
        // Increment the shared intrusive reference count atomically across threads.
        _InterlockedIncrement(&refCount);
    }

    void DecRefCount()
    {
        // Decrement the shared intrusive reference count atomically and destroy on the final release.
        std::uint32_t count = static_cast<std::uint32_t>(_InterlockedDecrement(&refCount));
        if (count == 0) {
            DeleteThis();
        }
    }

    long refCount;
    std::uint32_t unk0C;
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

template <class T>
class NiPointer
{
public:
    NiPointer& operator=(T* a_rhs)
    {
        if (_ptr != a_rhs) {
            T* old = _ptr;
            if (a_rhs) {
                a_rhs->IncRefCount();
            }
            _ptr = a_rhs;
            if (old) {
                old->DecRefCount();
            }
        }
        return *this;
    }

    T* _ptr;
};

class NiStream
{
public:
    NiObject* ReadLinkID();
};

class NiTimeController
{
public:
    void LinkObject(NiStream& a_stream);

    virtual void Unk_00();
    virtual void Unk_01();
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
    virtual void SetInterpolator(NiObject* a_interp, std::uint16_t a_index);

    std::uint8_t unk08[0x40];
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");

class BSProceduralLightningController : public NiTimeController
{
public:
    void LinkObject(NiStream& a_stream);

    std::uint8_t unk48[0xB8];
    NiPointer<NiObject> targetObject;
};
static_assert(offsetof(BSProceduralLightningController, targetObject) == 0x100, "targetObject offset");
