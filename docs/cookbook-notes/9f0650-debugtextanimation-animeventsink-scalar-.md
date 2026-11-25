# 0x9f0650 DebugTextAnimation::AnimEventSink::scalar deleting destructor

<!-- tags: construct/destructor, abi/virtual, sibling/fo4 -->

- Function: 0x9f0650 DebugTextAnimation::AnimEventSink::scalar deleting destructor (also 0x9f0710)
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 100%
- Attempts: 2

## What differed

The target destroys one member through an out-of-line call and only then stores a single vftable pointer, then frees the object. The first draft declared and defined an empty user-provided destructor on the derived class. That version stored the derived class's own vftable pointer before the member call and the event-sink base's pointer after it, so it was ten bytes too big.

## Spellings tried that did not help

- A user-provided empty destructor on the derived class (two vftable stores around the member call).

## Spelling that fixed it

Leave the destructor implicit and give the class only a constructor, defined in the unit so the compiler emits the vftable and the deleting destructor next to it:

```cpp
struct DebugTextAnimation {
    class AnimEventSink : public BSTEventSink<AnimEvent> {
    public:
        AnimEventSink();   // defined in the unit, empty
        EventHandle handle; // out-of-line destructor
    };
};
```

For the two-base sibling shape (0x3fd3e0, 0x44d580, 0x4508b0) a user-provided empty destructor was right: both base vftable pointers are stored once each and nothing is called in between, so there is no extra store.
