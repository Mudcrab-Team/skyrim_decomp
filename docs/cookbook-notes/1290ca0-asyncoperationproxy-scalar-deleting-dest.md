# 0x1290ca0 AsyncOperationProxy scalar deleting destructor

<!-- tags: construct/destructor, abi/virtual, sibling/fo4 -->

- Function: 0x1290ca0 AsyncOperationProxy scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 56/56
- Attempts: 1

## What differed

A deleting destructor that destroys one member through an out-of-line call and stores no vftable at all, although the class is polymorphic and the destructor is not slot 0.

## Spellings tried that did not help

none

## Spelling that fixed it

Declare the virtual destructor defaulted in the class body, after other virtuals so it is not slot 0, and give the member type an out-of-line destructor. A defaulted virtual destructor stores no vftable, an empty inline body would store one. The constructor is defined empty in the unit so the vftable and the deleting destructor are emitted. The same shape closed 0x1386ec0 (member at a different offset) and, with a base destructor call after the member destructor, 0x340570, 0x878b00 and 0x87c0b0.

```cpp
virtual void unk00();
virtual void unk01();
virtual void unk02();
virtual ~AsyncOperationProxy() = default;
```
