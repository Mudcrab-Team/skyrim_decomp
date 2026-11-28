// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: PropPtr226a00::operator= and Property226a00::DecRefCount, treated as adapted: shaped like NiPointer::operator= and NiRefObject::IncRefCount and NiRefObject::DecRefCount (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/N/NiSmartPointer.h:78, src/RE/N/NiRefObject.cpp:22, src/RE/N/NiRefObject.cpp:28, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Geometry226a00, Property226a00, PropPtr226a00, DeleteThis, DecRefCount, Attach, SetProperty, refCount, object, property128: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

class Geometry226a00;

class Property226a00
{
public:
    virtual ~Property226a00();
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
    virtual void Attach(Geometry226a00* owner);

    void DecRefCount()
    {
        // Atomic reference count decrement for shared property ownership.
        std::uint32_t count = _InterlockedDecrement(&refCount);
        if (count == 0)
        {
            DeleteThis();
        }
    }

    long refCount;  // 08
};

class PropPtr226a00
{
public:
    PropPtr226a00& operator=(Property226a00* rhs)
    {
        Property226a00* old = object;
        if (old != rhs)
        {
            if (rhs)
            {
                // Atomic reference count increment for shared property ownership.
                _InterlockedIncrement(&rhs->refCount);
            }
            object = rhs;
            if (old)
            {
                old->DecRefCount();
            }
        }
        return *this;
    }

    Property226a00* object;  // 00
};

class Geometry226a00
{
public:
    void SetProperty(Property226a00* prop);

    std::uint8_t unk00[0x128];  // 000
    PropPtr226a00 property128;  // 128
};
