// Source exposure: mixed (sibling game-code declarations; the pinned image listing).
// Code origin: adapted from the sibling list header, then checked against the image listing.
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSimpleList.h:66
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSimpleList.h:49
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bssystem/archive.cpp:5561 (same RemoveAll loop)
// BSSimpleList, m_item, m_pkNext, RemoveAll: SIBLING(fo4-private@1b765c70, author-permission)
// Unk1f0840Item: GUESS(low); the element type is unknown, only that it is a pointer
#pragma once

struct Unk1f0840Item;

template <class T>
class BSSimpleList
{
public:
    ~BSSimpleList();
    void RemoveAll(void (*a_delete)(BSSimpleList*, void*), void* a_data);

    T m_item;                // 00
    BSSimpleList* m_pkNext;  // 08
};

template <class T>
inline void BSSimpleList<T>::RemoveAll(void (*a_delete)(BSSimpleList*, void*), void* a_data)
{
    while (m_pkNext) {
        BSSimpleList* next = m_pkNext->m_pkNext;
        m_pkNext->m_pkNext = 0;
        if (a_delete) {
            a_delete(m_pkNext, a_data);
        } else {
            delete m_pkNext;
        }
        m_pkNext = next;
    }
    m_item = T();
}

template <class T>
inline BSSimpleList<T>::~BSSimpleList()
{
    RemoveAll(0, 0);
}
