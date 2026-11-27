// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Adapted bodies: TestBit, a one-line bit test close to a same-named sibling helper (CC0-1.0); it is the shape the matching cookbook gives
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
// SPDX-License-Identifier: CC0-1.0
// BSGeometry, BSGeometry::Functionefc7a0, TestBit, Child, vfunc26, unk18, unkF4, unk120, unk128, a_arg: GUESS(low)
// slot00 to slot25: GUESS(low); slot placeholders before vfunc26
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(uint32_t a_flags, uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Child
{
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot1A();
    virtual void slot1B();
    virtual void slot1C();
    virtual void slot1D();
    virtual void slot1E();
    virtual void slot1F();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void vfunc26(void* a_arg);

    uint8_t pad08[0x10];
    void*   unk18;
};

class BSGeometry
{
public:
    void Functionefc7a0(void* a_arg);

    uint8_t  pad00[0xF4];
    uint32_t unkF4;
    uint8_t  padF8[0x120 - 0xF8];
    Child*   unk120;
    Child*   unk128;
};
