// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTEvent.h:23
// BSTEventSink, ProcessEvent, AnimEventSink: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declaration
// DebugTextAnimation, AnimEvent, EventHandle, pReference, unk10: GUESS(low)
#pragma once

struct AnimEvent
{
};

template <class T>
class BSTEventSink
{
public:
    virtual ~BSTEventSink() {}
    virtual int ProcessEvent(const T& aEvent, void* apSource) = 0;
};

class EventHandle
{
public:
    ~EventHandle();

    void* pReference;
};

struct DebugTextAnimation
{
    class AnimEventSink : public BSTEventSink<AnimEvent>
    {
    public:
        AnimEventSink();
        int ProcessEvent(const AnimEvent& aEvent, void* apSource);

        EventHandle handle;
        unsigned char unk10[0x18];
    };
};
