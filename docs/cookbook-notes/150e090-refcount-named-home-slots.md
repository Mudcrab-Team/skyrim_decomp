# 0x150e090 ShadowSceneNode::ClearLightArrays

<!-- tags: abi/exception, wall/register-schedule, wall/inlining, construct/destructor -->

- Function: 0x150e090 ShadowSceneNode::ClearLightArrays (also 0x155c590, 0x155c750, 0x155c850, 0x155d830, 0x155d890, 0x155d970, 0x155dc00)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 343/343 from 313/343; eight functions of the shadow-light family closed
- Attempts: 4

## What differed
The round-one drafts of this group had identical instruction streams and differed only in the unwind info: the target saves its
first callee-saved register in the third incoming-argument home slot and keeps the temporaries in the second and third, the
draft started one slot lower. The copied light pointer was also stored after the lock-prefixed increment instead of before it.

## Spellings tried that did not help
- Const reference, by-value and copy-constructed temporaries, a third loop written out (round one).
- The permuter on the same sources: no site inside the body moves a home slot.

## Spelling that fixed it
Cookbook rule 29 applied to the shared smart-pointer helper: the release names the decremented count
(`long count = _InterlockedDecrement(&refCount); if (count == 0) DeleteThis();`), and the queued copy is built from a plain
`BSLight*` local (`NiPointer<BSLight> light(entry)`) so the pointer store precedes the increment. One edit to the helper closed
the whole family, including the destructor, deleting destructor and descriptor-release functions. The funclets then need the
folded out-of-line smart-pointer destructor bound locally.
