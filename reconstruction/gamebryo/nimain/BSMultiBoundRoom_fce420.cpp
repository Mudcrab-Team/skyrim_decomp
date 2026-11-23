// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfce420 BSMultiBoundRoom::ClearLinkedList
// Adapted bodies: none
#include "BSMultiBoundRoom_fce420.h"

void BSMultiBoundRoom::ClearLinkedList()
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
