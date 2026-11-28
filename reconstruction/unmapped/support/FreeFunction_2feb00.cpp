// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0x2feb00 Function2feb00
// Adapted bodies: none
#include "FreeFunction_2feb00.h"

// Removes target from the intrusive singly linked list rooted at g_head2feb00.
void Function2feb00(ListNode2feb00* target)
{
    ListNode2feb00* previous = g_head2feb00;
    if (previous == nullptr) {
        return;
    }

    ListNode2feb00* current = previous;
    do {
        if (current == target) {
            if (current == g_head2feb00) {
                g_head2feb00 = current->GetNext();
            } else {
                previous->SetNext(current->GetNext());
            }
            return;
        }
        previous = current;
        current = current->GetNext();
    } while (current != nullptr);
}
