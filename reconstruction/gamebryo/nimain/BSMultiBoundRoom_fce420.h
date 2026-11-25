// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSMultiBoundRoom, ClearLinkedList, ListNode, next, item, head, tail, count: GUESS(low); stand-in class view, the object is a singly linked list header
#pragma once
#include <cstdint>

struct ListNode
{
    ListNode* next;     // 00
    void* unk08;    // 08
    void* item;     // 10
};

class BSMultiBoundRoom
{
public:
    void ClearLinkedList();  // compared: 0xfce420

    ListNode* head;           // 00
    ListNode* tail;           // 08
    std::uint32_t count;  // 10
};
