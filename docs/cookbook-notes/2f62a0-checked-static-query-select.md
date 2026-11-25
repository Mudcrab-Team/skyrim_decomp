# 0x2f62a0 TESObjectREFR::Function2f62a0

<!-- tags: method/diagnostic, wall/control-flow, wall/register-schedule -->

- Function: 0x2f62a0 TESObjectREFR::Function2f62a0
- Label: GUESS(low)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 34/51 matching bytes, alignment distance 3.0, size 51/51; not a byte match
- Attempts: 4 counted comparisons, plus one PC permute search of 81 candidates

## What differed
The reference checks its base object, checks the Static form type, selects a null or static-object pointer,
and calls the sky-object predicate only for a valid cast. The first draft has the target's instruction
count and size, but its pointer selection uses different scratch-register roles and a different select
form. Native Windows comparison did not pass. The placeholder query name is inferred; the field names
are community declarations and the called predicate name is from the community-generated CrashLogger output.

## Spellings tried that did not help
The explicit null-initialized pointer followed by a type-test ternary is the best alignment state.
An in-place pointer clear on type mismatch produced a size mismatch at distance 3.5. A separate inline
checked-cast helper with a named boolean produced a size mismatch at distance 6.0; a helper returning
null on a mismatched type gave distance 3.5. The highest raw matching-byte count was 39/51, from the
worse distance-6.0 state. A one-worker native Windows permutation search retained distance 3.0 after
81 candidates and stopped on patience. Cookbook rules 40 and 65 guided the helper experiments but
did not close this function. Three subsequent comparisons failed to improve the best alignment.

## Spelling that fixed it
None. Preserve the first draft as the near miss; all four failed source snapshots and their comparator
reports remain private. No excluded middleware sibling bodies were read or adapted.
