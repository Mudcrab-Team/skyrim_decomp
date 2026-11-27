// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xcd4da0 SoundMessageList::AddHead
#include "SoundMessageList_cd4da0.h"

// Prepends a message node to the head of the doubly linked list.
void SoundMessageList::AddHead(SoundMessage* a_msg)
{
    if (!head && !tail)
    {
        tail = a_msg;
        head = a_msg;
        return;
    }

    a_msg->next = head;
    a_msg->prev = nullptr;
    head->prev = a_msg;
    head = a_msg;
}
