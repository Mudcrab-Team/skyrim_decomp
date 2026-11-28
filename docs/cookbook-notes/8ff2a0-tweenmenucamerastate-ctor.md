# 0x8ff2a0 TweenMenuCameraState::ctor

<!-- tags: method/diagnostic -->

- Function: 0x8ff2a0 TweenMenuCameraState::ctor
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: instruction-order
- Best score: 104/104 (aligned_matching_bytes)
- Attempts: 4

## What differed

The first draft placed the intrusive reference count directly on `TESCameraState` and zeroed the tail fields in the initializer list while assigning the two `NiPoint2` fields in the constructor body. That moved the `camera` store before the vftable store, zeroed the tail fields ahead of the `NiPoint2` copies, and swapped the two floating-point temporaries across the two `NiPoint2` copies.

## Spellings tried that did not help

- Putting `refCount` directly on `TESCameraState` instead of a base class caused `camera` to be stored before the vftable.
- Zeroing the tail fields in the initializer list while assigning `currentRotation` and `targetRotation` in the body placed the tail zeroing before the `NiPoint2` loads.
- Moving the tail zeroing after the body assignments aligned the whole sequence, but left the two floating-point temporaries swapped in the `NiPoint2` copies.

## Spelling that fixed it

Inherited `TESCameraState` from a base `BSIntrusiveRefCounted` holding `refCount`, gave `NiPoint2` a memberwise copy constructor used in the member initializer list for `currentRotation` and `targetRotation`, and zeroed the trailing state fields in the constructor body:

```cpp
TweenMenuCameraState::TweenMenuCameraState(TESCamera* a_camera, std::uint32_t a_id) :
    TESCameraState8ff2a0(a_camera, a_id), initialRotation(gIdentityQuat), unk30(0),
    currentRotation(gZeroPoint2), targetRotation(gZeroPoint2)
{
    unk44 = 0;
    unk48 = 0;
    unk4C = false;
}
```
