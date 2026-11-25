# 0x639a20 BGSSaveGameBuffer::Save

<!-- tags: construct/serialization, abi/calling-convention, wall/register-schedule, wall/inlining -->

- Function: 0x639a20 BGSSaveGameBuffer::Save
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 68/84 aligned matching bytes; candidate size 84/84
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The initial callback declaration used a boolean final argument, making that stack argument too narrow and producing an 81-byte candidate. A 32-bit unsigned final callback argument gives the observed 84-byte extent and improves the score from 62/84 to 68/84. Two constant argument stores still occur in the opposite order. This is the same unresolved scheduling cause recorded for this RVA in cookbook rule 42; the callback-width correction is a separate partial improvement.

## Spellings tried that did not help
The direct callback spelling, an ordinary inline file-callback facade with a local element size, and the same facade taking that element size by value all scored 68/84 after the width correction. The bounded PC permuter used one job, batches of eight and a 60-second budget; its pool exhausted after 241 candidates at unchanged distance 1.0. The simpler direct-call source was restored and compared once more; three consecutive comparisons without improvement reached the assigned stop rule. All failed sources remain in the private task history.

## Spelling that fixed it
none
