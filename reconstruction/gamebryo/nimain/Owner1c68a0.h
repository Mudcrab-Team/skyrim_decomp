// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xfce420 (gamebryo/nimain/BSMultiBoundRoom_fce420): source copied, names replaced by placeholders.
// ListNode: GUESS(low); stand-in class view, the object is a singly linked list header
// Function1c68a0, Owner1c68a0: GUESS(low) STANDIN
// head, tail, count: GUESS(low) STANDIN
#pragma once
#include "BSMultiBoundRoom_fce420.h"

class Owner1c68a0
{
public:
    void Function1c68a0();

    ListNode* head;           // 00
    ListNode* tail;           // 08
    std::uint32_t count;  // 10
};

