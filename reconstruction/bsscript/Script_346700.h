// Source exposure: mixed (community declarations and the contributor-owned pack).
// Code origin: list template adapted from the sibling source lines below; the instantiation is read from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSimpleList.h:49
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSimpleList.h:66
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561
// BSSimpleList, BSSimpleList::RemoveAll, BSSimpleList::m_item, BSSimpleList::m_pkNext: SIBLING(fo4-private@1b765c70, author-permission)
// Script: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the list member whose element destructor is compared
// Script::refObjects: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Script::unknown00: GUESS(low)
// SCRIPT_REFERENCED_OBJECT: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); which Script list this instantiation serves is a guess
#pragma once

#include <cstdint>
#include <cstddef>

struct SCRIPT_REFERENCED_OBJECT;

template <class T>
class BSSimpleList
{
public:
    BSSimpleList() : m_item(), m_pkNext(0) {}
    ~BSSimpleList();  // compared: 0x346700 for T = SCRIPT_REFERENCED_OBJECT*
    void RemoveAll(void (*pfnDelete)(BSSimpleList*, void*), void* pData);

    T m_item;                // 0
    BSSimpleList* m_pkNext;  // 8
};

template <class T>
inline void BSSimpleList<T>::RemoveAll(void (*pfnDelete)(BSSimpleList*, void*), void* pData)
{
    while (m_pkNext) {
        BSSimpleList* pkNext = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        if (pfnDelete)
            pfnDelete(m_pkNext, pData);
        else
            delete m_pkNext;
        m_pkNext = pkNext;
    }
    m_item = T();
}

template <class T>
inline BSSimpleList<T>::~BSSimpleList()
{
    RemoveAll(0, 0);
}

class Script
{
public:
    std::uint8_t unknown00[0x60];                       // 00
    BSSimpleList<SCRIPT_REFERENCED_OBJECT*> refObjects;  // 60
};
