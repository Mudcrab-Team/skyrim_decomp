// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xfce420 (gamebryo/nimain/BSMultiBoundRoom_fce420): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x1c68a0 Owner1c68a0::Function1c68a0
#include "Owner1c68a0.h"

// guess: same compiled code as matched 0xfce420 apart from relocated fields; its role here is not established.
void Owner1c68a0::Function1c68a0()
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
