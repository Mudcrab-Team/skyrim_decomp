// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00dba7a0_cls::AssignRefCounted.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/havok/common/serialize/data/hkdataobject.cpp:1350
// 0xc5a930 Func00dba7a0_cls::AssignRefCounted
#include "Func00dba7a0_cls_c5a930.h"

void Func00dba7a0_cls::AssignRefCounted(Func00dba7a0_cls* src)
{
    RefCountedObj* newObj = src->m_pEntryObject;
    if (newObj)
    {
        newObj->m_refFlags++;
        newObj->m_iObjectReferenceCount++;
    }
    RefCountedObj* oldObj = m_pEntryObject;
    if (oldObj)
    {
        int delta = -1;
        oldObj->m_refFlags += delta;
        oldObj->m_iObjectReferenceCount += delta;
        if (oldObj->m_iObjectReferenceCount == 0)
        {
            delete oldObj;
            m_pEntryObject = src->m_pEntryObject;
            return;
        }
        m_pEntryObject = src->m_pEntryObject;
        return;
    }
    m_pEntryObject = src->m_pEntryObject;
}
