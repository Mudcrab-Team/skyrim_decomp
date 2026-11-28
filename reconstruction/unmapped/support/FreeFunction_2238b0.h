// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: UpdateControllersRecursive2238b0, treated as adapted: shaped like a recursive scene node walk in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/unmapped/bhkrigidbody.cpp:2118
// SPDX-License-Identifier: CC0-1.0
// NiTimeController2238b0, NiNode2238b0, NiAVObject2238b0, UpdateController, AsNode, UpdateControllersRecursive2238b0, next, controllers, children, childCount: GUESS(low)
#pragma once

#include <cstdint>

class NiTimeController2238b0
{
public:
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
    virtual void UpdateController();

    std::uint8_t unk08[0x38];       // 08
    NiTimeController2238b0* next;   // 40
};

class NiNode2238b0;

class NiAVObject2238b0
{
public:
    virtual ~NiAVObject2238b0();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode2238b0* AsNode();

    std::uint8_t unk08[0x10];            // 008
    NiTimeController2238b0* controllers; // 018
    std::uint8_t unk20[0xF8];            // 020
};

class NiNode2238b0 : public NiAVObject2238b0
{
public:
    NiAVObject2238b0** children;  // 118
    std::uint16_t maxSize;        // 120
    std::uint16_t childCount;     // 122
};

void UpdateControllersRecursive2238b0(NiAVObject2238b0* obj);
