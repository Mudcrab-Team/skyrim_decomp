// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation; adapted bodies: BSAnimNoteListener::Update.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a40000_o2.cpp:835
// 0xf6a620 BSAnimNoteListener::Update
#include "BSAnimNoteListener_f6a620.h"

void BSAnimNoteListener::Update(HandlerArg* a1)
{
    for (unsigned int i = 0; i < m_uiItemCount; ++i)
    {
        HandlerEntry* e = m_ppEntries[i];
        if (e->m_key == a1->m_key)
        {
            e->m_pEntryObject->Handle(a1);
        }
    }
}
