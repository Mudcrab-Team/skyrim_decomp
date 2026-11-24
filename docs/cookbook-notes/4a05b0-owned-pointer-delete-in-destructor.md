# 0x4a05b0 TESDialoguePackageData scalar deleting destructor

- Function: 0x4a05b0 TESDialoguePackageData scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: 87/87
- Attempts: 1

## What differed

The wrapper null-checks an owned pointer and calls slot 0 of its vftable with flag 1, then stores
the base vftable before the sized delete. NiOBBNode 0xf409d0 deletes two owned pointers, but the
second null check jumps to the same exit as the first.

## Spellings tried that did not help

none

## Spelling that fixed it

Write `delete member;` in the inline destructor, where the member's type has a virtual destructor,
and give the base an inline empty root destructor. For NiOBBNode, nest the second delete inside the
first pointer's check. The compiler keeps the second null check and the shared exit.

```cpp
virtual ~NiOBBNode()
{
    if (unk88)
    {
        delete unk88;
        delete unk90;
    }
}
```
