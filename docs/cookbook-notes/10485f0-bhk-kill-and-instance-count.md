# 0x10485f0 bhkWorldObject scalar deleting destructor

<!-- tags: abi/virtual, construct/destructor, method/diagnostic, method/sibling, sibling/fnv, wall/inlining -->

- Function: 0x10485f0 bhkWorldObject scalar deleting destructor
- Label: EXE_RTTI
- Outcome: fixed
- Cause: inlining
- Best score: 89/89
- Attempts: 1

## What differed

Each bhk deleting destructor in this set stores one vftable, calls a release helper on `this`,
decrements a global instance counter, and then calls the next base destructor out of line.
bhkConvexSweepShape has no counter decrement.

## Spellings tried that did not help

none

## Spelling that fixed it

Use the chain spelling from 12db40-inlined-destructor-chain.md and put two statements in the inline
destructor: a call to a declared member and a decrement of a declared static counter. The FNV sibling
calls the helper bhkSerializable_Kill. The same body matched all 29. The unit file-name pattern accepts `hk` prefixes but not `bhk`, so
the owner class is spelled `Bhk...` as a STANDIN, as the existing bshavok units do. The other bhk
bases keep their RTTI spelling, and the bytes do not change.

```cpp
~BhkWorldObject() override
{
    Kill();
    --sInstanceCount;
}
```
