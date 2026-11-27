# 0x150e090 ShadowSceneNode::ClearLightArrays

<!-- tags: wall/register-schedule, abi/exception, method/sibling -->

- Function: 0x150e090 ShadowSceneNode::ClearLightArrays (also 0x150fe80, 0x150c710, 0x150e500)
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 343 of 343 bytes with the same states and ip map; the unwind info differs
- Attempts: 9

## What differed
`ClearLightArrays` walks two arrays of counted light pointers, queues a copy of each, then clears the shadow caster array. After
switching to the sibling `BSTArray` and `NiPointer` the code, the three EH states and the ip map match. The two temporaries
sit one eight-byte slot lower in the draft, so the unwind info differs. The same one-slot or register-role shift keeps three
other functions short: 0x150fe80 (the light and the node swap between rdx and r10), 0x150c710 (frame set-up stores in the
other order, this and the argument swap callee-saved registers), 0x150e500 (rbx and rdi swapped).

## Spellings tried that did not help
- Const reference, by-value and copy-constructed temporaries for the queued pointer.
- The third loop written out or as a call to `ClearShadowCasterArray`.
- Permuter runs on 0x150fe80, 0x150c710 and 0x150e500 (best distance 9, 3 and 1, no gain).

## Spelling that fixed it
none.
