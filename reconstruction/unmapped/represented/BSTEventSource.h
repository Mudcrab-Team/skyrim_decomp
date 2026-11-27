// Source exposure: mixed (pinned executable and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original destructor reconstruction using community layout declarations.
// Adapted bodies: none
// BSTArray, BSTArrayBase, BSTArrayHeapAllocator, BSTEventSource, BSTEventSink, BSSpinLock and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Event types and ownership of these specializations: GUESS(low) STANDIN
#pragma once

namespace event_source_teardown
{
    struct BSTArrayBase
    {
        unsigned size;
        ~BSTArrayBase();
    };

    struct BSTArrayHeapAllocator
    {
        void* data;
        unsigned capacity;
        ~BSTArrayHeapAllocator();
        void Deallocate();
    };

    template <class T>
    struct BSTArray : BSTArrayHeapAllocator, BSTArrayBase
    {
        ~BSTArray();
    };

    template <class Event> struct BSTEventSink;

    struct BSSpinLock
    {
        unsigned ownerThread;
        unsigned lockCount;
    };

    template <class Event>
    struct BSTEventSource
    {
        using SinkArray = BSTArray<BSTEventSink<Event>*>;
        SinkArray sinks;
        SinkArray pendingRegisters;
        SinkArray pendingUnregisters;
        BSSpinLock lock;
        bool notifying;
        ~BSTEventSource();
    };

    static_assert(sizeof(BSTEventSource<void>) == 0x58, "event source size");
}
