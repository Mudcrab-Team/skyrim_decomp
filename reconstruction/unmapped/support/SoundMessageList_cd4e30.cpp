// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xcd4e30 SoundMessageList::AddTail
#include "SoundMessageList_cd4e30.h"

// Appends a message node to the tail of the doubly linked list.
void SoundMessageList::AddTail(SoundMessage* a_msg)
{
    if (!head && !tail)
    {
        head = a_msg;
        tail = a_msg;
        return;
    }

    a_msg->prev = tail;
    a_msg->next = nullptr;
    tail->next = a_msg;
    tail = a_msg;
}
