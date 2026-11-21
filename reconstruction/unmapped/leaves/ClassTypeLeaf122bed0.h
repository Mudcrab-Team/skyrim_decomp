// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: CC0-1.0
// ClassTypeLeaf122bed0, ClassTypeLeaf122bed0::QClassType: GUESS(low) STANDIN
#pragma once

class StaticType122bed0
{
public:
    StaticType122bed0();
    StaticType122bed0(const StaticType122bed0& a_other);
    ~StaticType122bed0();
    void* field00;  // 00
};
static_assert(sizeof(StaticType122bed0) == 8, "eight-byte static object");
extern StaticType122bed0 globalSource122bed0;

class ClassTypeLeaf122bed0
{
public:
    StaticType122bed0* QClassType();  // compared: 0x122bed0
};
