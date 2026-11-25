// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00dba7a0_cls: GUESS(low); placeholder name
// Func00dba7a0_cls::AssignRefCounted: GUESS(low); placeholder name
#pragma once

struct RefCountedObj;


struct RefCountedObj
{
    virtual ~RefCountedObj()
    {}
    unsigned short unk04;
    short m_refFlags;
    int m_iObjectReferenceCount;
};

struct Func00dba7a0_cls
{
    RefCountedObj* m_pEntryObject;
    void AssignRefCounted(Func00dba7a0_cls* src);
};
