# 0x12db40 UI_Text3 scalar deleting destructor

- Function: 0x12db40 UI_Text3 scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 62/62
- Attempts: 2

## What differed

The sibling transplant emitted a thunk that only called the destructor, but the target inlines the
whole destructor chain into the deleting wrapper: it stores one vftable, calls one base destructor
out of line, then frees the object with the sized delete. Which vftable is stored decides which class
must own the inline destructor; the RTTI owner of slot 0 is often a derived class whose own
destructor stores nothing.

## Spellings tried that did not help

Declaring an inline override on every level of the chain: each user-declared inline destructor stores
its own vftable, so the wrapper gained one store per level.

## Spelling that fixed it

Give the class whose vftable the wrapper stores a user-declared inline destructor, declare the next
base destructor out of line (`virtual ~Base();`, not defined), and leave every level above the stored
class with an implicit destructor. Emit the vftable with an empty out-of-line constructor and pad the
most-derived class to the delete size with a static_assert. The same spelling matched 64 functions.

```cpp
class Base { public: Base(); virtual ~Base(); };
class Stored : public Base { public: Stored(); ~Stored() override {} };
class Owner : public Stored { public: Owner(); char unk08[0x18]; };
Owner::Owner() {}
```
