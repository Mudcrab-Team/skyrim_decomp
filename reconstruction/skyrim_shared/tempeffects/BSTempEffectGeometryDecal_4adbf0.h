// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSTempEffectGeometryDecal, Assign, RefObject, refCount, ref: GUESS(low); stand-in class view, the class holds one intrusive reference at offset 0
#pragma once
#include <cstdint>

class RefObject
{
public:
    virtual ~RefObject();  // 00

    std::int32_t refCount;  // 08
};

class BSTempEffectGeometryDecal
{
public:
    BSTempEffectGeometryDecal* Assign(RefObject* a_other);  // compared: 0x4adbf0

    RefObject* ref;  // 00
};
