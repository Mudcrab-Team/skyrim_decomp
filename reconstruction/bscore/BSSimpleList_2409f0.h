// Source exposure: mixed (sibling game-code declarations; the pinned image listing).
// Code origin: adapted from the sibling list header, then checked against the image listing.
// Sibling source: fo4-private@1b765c70 src/BSCore/BSSimpleList.h:112
// BSSimpleList, m_item, m_pkNext, AddHead: SIBLING(fo4-private@1b765c70, author-permission)
// MESSAGEBOX_BUTTON: GUESS(low); opaque element type, only its pointer is stored
// MemMgrGuard_369ac98, MemMgrInst_369a810, MemMgrEnsure_cde810, MemMgrAlloc_cde250: GUESS(low); the heap singleton, its init guard and its allocation call
#pragma once

#include <cstddef>
#include <cstdint>

struct MESSAGEBOX_BUTTON;

extern "C" {
    extern std::uint32_t MemMgrGuard_369ac98;
    extern std::uint8_t MemMgrInst_369a810[1];
    void __cdecl MemMgrEnsure_cde810(void* self, std::uint32_t* state);
    void* __cdecl MemMgrAlloc_cde250(void* self, std::size_t size, std::uint32_t align, bool alignReq);
}

template <class T>
class BSSimpleList
{
public:
    // Nodes come from the game heap, whose singleton is initialised on first use.
    static void* operator new(std::size_t a_size) throw()
    {
        if (MemMgrGuard_369ac98 != 2u) {
            MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
        }
        return MemMgrAlloc_cde250(MemMgrInst_369a810, a_size, 0u, false);
    }

    BSSimpleList(const T& a_item) : m_item(a_item), m_pkNext(0) {}
    void AddHead(const T& a_item, BSSimpleList* (*a_create)(T, void*), void* a_data);

    T m_item;                // 00
    BSSimpleList* m_pkNext;  // 08
};

template <class T>
inline void BSSimpleList<T>::AddHead(const T& a_item, BSSimpleList* (*a_create)(T, void*), void* a_data)
{
    if (a_item) {
        if (m_item) {
            BSSimpleList* node = a_create ? a_create(m_item, a_data) : new BSSimpleList(m_item);
            node->m_pkNext = m_pkNext;
            m_pkNext = node;
            m_item = a_item;
        } else {
            m_item = a_item;
        }
    }
}
