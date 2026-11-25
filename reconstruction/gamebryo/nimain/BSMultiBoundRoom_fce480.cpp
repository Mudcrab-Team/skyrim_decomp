// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfce480 BSMultiBoundRoom::ClearLinkedList2
// Adapted bodies: none
#include "BSMultiBoundRoom_fce480.h"

void BSMultiBoundRoom::ClearLinkedList2()
{
    ListNode* cursor = head;
    while (cursor) {
        ListNode* node = cursor;
        cursor = cursor->next;
        node->item = nullptr;
        delete node;
    }
    count = 0;
    head = nullptr;
    tail = nullptr;
}
