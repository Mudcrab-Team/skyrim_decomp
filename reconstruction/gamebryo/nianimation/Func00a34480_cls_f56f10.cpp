// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: Func00a34480_cls::Func00a34480.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/nicontrollersequence.cpp:1305
// 0xf56f10 Func00a34480_cls::Func00a34480
#include "Func00a34480_cls_f56f10.h"

bool Func00a34480_cls::Func00a34480(void* a1, Func00a34480_obj* pNode)
{
    Func00a34480_obj* cur = 0;
    if (a1 != 0)
    {
        if (pNode != 0)
        {
            cur = pNode->V02();
            if (cur != 0)
            {
                do
                {
                    if (cur == (Func00a34480_obj*)&Data011f36b4)
                    {
                        goto found;
                    }
                    cur = cur->m_pNext;
                } while (cur != 0);
            }
        }
    }
    return false;

found:
    unsigned short flags = (unsigned short)(m_word24 + m_word24);
    flags = (unsigned short)(flags | (pNode->m_word08 & 0xfff9));
    pNode->m_word08 = flags;
    pNode->m_f0c = m_f28;
    pNode->m_word08 = (unsigned short)(pNode->m_word08 & 0xffef);
    return AssignControllers(a1, pNode);
}
