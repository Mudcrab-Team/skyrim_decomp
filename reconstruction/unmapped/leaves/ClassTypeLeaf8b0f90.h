// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: CC0-1.0
// ClassTypeLeaf8b0f90, ClassTypeLeaf8b0f90::QClassType: GUESS(low) STANDIN
#pragma once

class StaticType8b0f90
{
public:
    StaticType8b0f90();
    StaticType8b0f90(const StaticType8b0f90& a_other);
    ~StaticType8b0f90();
    void* field00;  // 00
};
static_assert(sizeof(StaticType8b0f90) == 8, "eight-byte static object");
extern StaticType8b0f90 globalSource8b0f90;

class ClassTypeLeaf8b0f90
{
public:
    StaticType8b0f90* QClassType();  // compared: 0x8b0f90
};
