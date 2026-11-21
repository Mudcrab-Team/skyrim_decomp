// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: CC0-1.0
// ClassTypeLeaf122c1e0, ClassTypeLeaf122c1e0::QClassType: GUESS(low) STANDIN
#pragma once

class StaticType122c1e0
{
public:
    StaticType122c1e0();
    StaticType122c1e0(const StaticType122c1e0& a_other);
    ~StaticType122c1e0();
    void* field00;  // 00
};
static_assert(sizeof(StaticType122c1e0) == 8, "eight-byte static object");
extern StaticType122c1e0 globalSource122c1e0;

class ClassTypeLeaf122c1e0
{
public:
    StaticType122c1e0* QClassType();  // compared: 0x122c1e0
};
