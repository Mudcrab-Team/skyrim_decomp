// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiParticleSystem, NiPSysModifier, NiPSysData, NiParticlesData, NiPoint3, NiPointer, NiTListItem, Initialize, NiTPointerList, modifierList, particleData, head, next, prev, element: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InitializeModifiers: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiPSysData;
class NiParticlesData;
class NiPoint3;

// NiPSysModifier: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0x26 only
class NiPSysModifier
{
public:
    // Unk_00 to Unk_25: GUESS(low); placeholders for the earlier slots
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
    virtual void Initialize(NiParticlesData* a_particleData, std::uint16_t a_arg2, NiPoint3* a_arg3);  // 26
};

// NiPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the arrow access
template <class T>
class NiPointer
{
public:
    T* operator->() const { return _ptr; }

    T* _ptr;  // 00
};

// NiTListItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
template <class T>
class NiTListItem
{
public:
    NiTListItem* next;     // 00
    NiTListItem* prev;     // 08
    T            element;  // 10
};

// NiTPointerList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the head of its NiTListBase only
template <class T>
class NiTPointerList
{
public:
    NiTListItem<T>* head;  // 00
};

class NiParticleSystem
{
public:
    void InitializeModifiers(std::uint16_t a_arg1, NiPoint3* a_arg2);  // compared: 0xf999c0

    std::uint8_t                              pad000[0x158];  // 000
    NiParticlesData*                          particleData;   // 158
    std::uint8_t                              pad160[0x8];    // 160
    NiTPointerList<NiPointer<NiPSysModifier>> modifierList;   // 168
};
static_assert(offsetof(NiParticleSystem, modifierList) == 0x168, "modifierList offset");
