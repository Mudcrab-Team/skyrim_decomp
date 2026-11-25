// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original stand-in declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiControllerSequence, NiControllerSequence::InterpArrayItem, arraySize, interpArray, interpolator, interpCtlr, blendInterp, blendIdx, NiBlendInterpolator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionf59be0, RemoveInterpolator, unknown00, unknown19, unknown1C, Slot00, Slot01, Slot02, Slot03, Slot04, Slot05, Slot06, Slot07, Slot08, Slot09, Slot0A, Slot0B, Slot0C, Slot0D, Slot0E, Slot0F, Slot10, Slot11, Slot12, Slot13, Slot14, Slot15, Slot16, Slot17, Slot18, Slot19, Slot1A, Slot1B, Slot1C, Slot1D, Slot1E, Slot1F, Slot20, Slot21, Slot22, Slot23, Slot24, Slot25, Slot26, Slot27, Slot28, Slot29, Slot2A, Slot2B, Slot2C, Slot2D, Slot2E, Slot2F, Slot30, Slot31, Slot32, Slot33, Slot34, Slot35, Slot36, Slot37, Slot38, Slot39: GUESS(low); unknown virtual slots precede the observed blend operation.
#pragma once
#include <cstdint>
#include <cstddef>

class NiBlendInterpolator
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void RemoveInterpolator(std::uint8_t index);
};

class NiControllerSequence
{
public:
    struct InterpArrayItem
    {
        void* interpolator;
        void* interpCtlr;
        NiBlendInterpolator* blendInterp;
        std::uint8_t blendIdx;
        std::uint8_t unknown19[7];
    };
    void Functionf59be0();
    std::uint8_t unknown00[0x18];
    std::uint32_t arraySize;
    std::uint32_t unknown1C;
    InterpArrayItem* interpArray;
};
static_assert(sizeof(NiControllerSequence::InterpArrayItem) == 0x20, "item stride");
static_assert(offsetof(NiControllerSequence, interpArray) == 0x20, "array offset");
