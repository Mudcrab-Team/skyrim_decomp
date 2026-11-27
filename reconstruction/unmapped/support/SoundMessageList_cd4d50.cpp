// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// Adapted bodies: none
// 0xcd4d50 SoundMessageList::RemoveHead
#include "SoundMessageList_cd4d50.h"

// Detaches and returns the head message node from the doubly linked list.
SoundMessage* SoundMessageList::RemoveHead()
{
    SoundMessage* result = nullptr;
    if (head || tail)
    {
        result = head;
        if (head == tail)
        {
            tail = nullptr;
            head = nullptr;
        }
        else
        {
            head = head->next;
            if (head)
            {
                head->prev = nullptr;
            }
            result->next = nullptr;
            result->prev = nullptr;
        }
    }
    return result;
}
