# 0x14c810 TESFullName::deleting destructor

<!-- tags: construct/destructor, abi/virtual, sibling/fo4 -->

- Function: 0x14c810 TESFullName::deleting destructor
- Label: COMMUNITY
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 76/76
- Attempts: 3

## What differed

The sibling lead named a templated typed-item deleting destructor, whose first vtable store, a call to one
member destructor and a last store of the base vtable all look the same as a component with a string member.
A first draft built from the lead's class chain needed an explicit empty destructor on a middle class to keep
the first store. That matched, but the class chain was a wrong identity: the community and CrashLogger names put
the function in the form component class, which is a component with a base that has an empty inline destructor
and a string member with an out-of-line destructor.

## Spellings tried that did not help

- A template with an implicit destructor and a conditional-item base: the first vptr store was dropped.

## Spelling that fixed it

Use the real component shape: a component base with an inline empty virtual destructor, a derived class with the
destructor defined in the unit, and a string member whose destructor is declared and not defined.

```cpp
class TESFullName : public BaseFormComponent { ~TESFullName() override; BSFixedString fullName; };
TESFullName::~TESFullName() {}
```

The same bytes (a store of the class's own vtable, one member destructor call, a store of the base vtable, size
0x10) are the deleting destructor of every two-vptr component with one string member: 0x1f33d0 (the texture
component) is the same function with another vtable. Check the community or CrashLogger owner name before
inventing a class chain from the sibling lead, because a sibling name that compiles to the same code can still
be the wrong class.
