// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTEvent.h:23
// BSTEventSink, ProcessEvent: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declaration
// VATSFaceEmotionManager, EventA, EventB: GUESS(low)
#pragma once

struct EventA
{
};

struct EventB
{
};

template <class T>
class BSTEventSink
{
public:
    virtual ~BSTEventSink() {}
    virtual int ProcessEvent(const T& aEvent, void* apSource) = 0;
};

class VATSFaceEmotionManager : public BSTEventSink<EventA>, public BSTEventSink<EventB>
{
public:
    VATSFaceEmotionManager();
    ~VATSFaceEmotionManager();
    int ProcessEvent(const EventA& aEvent, void* apSource);
    int ProcessEvent(const EventB& aEvent, void* apSource);
};
