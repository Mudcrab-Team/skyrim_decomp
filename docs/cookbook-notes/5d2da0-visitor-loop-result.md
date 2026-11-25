# 0x5d2da0 MagicTarget::FindFirstEffectWithArchetype

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0x5d2da0 MagicTarget::FindFirstEffectWithArchetype
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: loop-shape
- Best score: 143/143 code bytes; comparator PASS, unwind covered
- Attempts: 4 counted comparisons on this lead (plus earlier history)

## What differed
The first draft broke out of the walk on a match. The target keeps the selected effect as loop state, declares it after the list pointer is fetched, and tests it at the top of every iteration; the inactive-flag test is a load, shift, complement and test of the low bit, not a memory mask test.

## Spellings tried that did not help
- Breaking when an effect matched (23/143).
- Direct `(flags >> 15) & 1` and a bit-field member: the compiler folded both into a memory mask test.

## Spelling that fixed it
Walk with `for (; node && !result; node = node->next)`, assign `result = effect` on a match, fetch the list pointer before declaring the result, and test the flag with a by-value clear-bit helper `(~(word >> bit) & 1) != 0` (cookbook rule 16, the clear-bit form that closed 0x3bfc00).
