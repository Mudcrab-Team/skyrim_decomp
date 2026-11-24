# 0x1e0000 TESContainer::~TESContainer

<!-- tags: construct/destructor, abi/exception, sibling/fo4 -->

- Function: 0x1e0000 TESContainer::~TESContainer
- Label: GUESS
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 50/50
- Attempts: 3

## What differed

The target stores the base vftable last and keeps the exception-state slot (the minus-two store) in a
form-component destructor that only calls one out-of-line helper. The first draft modelled the pointer and
count pair as a member object with an out-of-line destructor. That compiled to the same stores minus the
exception-state slot, six bytes short, and the comparator pointed at cookbook rule 13 (send to triage).
It is not a wall: a plain destructor body that calls an out-of-line member function keeps the slot when the
base has an inline virtual destructor.

## Spellings tried that did not help

A member subobject whose destructor is the out-of-line call: no exception-state slot, the body shrinks.

## Spelling that fixed it

Give the class an out-of-line destructor whose body calls a declared-only member function, and give the
base an inline empty virtual destructor (a small stand-in base). The same shape passed first time for
four more form components and one unidentified class (0x1e8810, 0x1f0a90, 0x1de7b0, 0x1ef970, 0x1461b10);
a member that owns an out-of-line destructor (a list or an array) is destroyed after the helper call.

```cpp
class BaseFormComponent { public: virtual ~BaseFormComponent() {} };
class TESContainer : public BaseFormComponent
{
public:
    ~TESContainer() override;
    void FreeObjectList();
};
TESContainer::~TESContainer() { FreeObjectList(); }
```
