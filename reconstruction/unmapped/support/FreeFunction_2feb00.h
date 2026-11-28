// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// ListNode2feb00, g_head2feb00, Function2feb00, Slot0, Slot1, Slot2, GetNext, SetNext, nextNode, target: GUESS(low)
#pragma once

struct ListNode2feb00
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual ListNode2feb00* GetNext();
    virtual void SetNext(ListNode2feb00* nextNode);
};

extern ListNode2feb00* g_head2feb00;

void Function2feb00(ListNode2feb00* target);
