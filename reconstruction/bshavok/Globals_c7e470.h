// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ApplyTransformToTarget: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); sibling name, identity with this function unproven
// padding_0_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

extern "C" void ApplyTransformToTarget(void*, void*, void*, void*);

struct Holder;
struct TargetObject;
struct Transform;
struct ValueSource;


struct __declspec(align(16)) Transform
{
    float m_f00;
    float m_f04;
    float m_f08;
    float m_f0c;
    float m_f10;
    float m_f14;
    float m_f18;
    float m_f1c;
    float m_f20;
    float m_f24;
    float m_f28;
    float m_f2c;
    float m_f30;
    float m_f34;
    float m_f38;
    float m_f3c;

    Transform(void* apFirst, void* apSecond);
};

struct TargetObject
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(Transform* apTransform, float afAmount, void* apContext);
};

struct Holder
{
    TargetObject* m_pFlagTarget;
    int unk04;
    void* m_pData;
};

// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct ValueSource
{
  public:
    char padding_0_[16];
    float m_fAmount;
};

struct Globals
{
};
