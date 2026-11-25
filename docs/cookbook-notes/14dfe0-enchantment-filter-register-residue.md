# 0x14dfe0 EnchantmentItem::EnchantmentItemFilterValidationFunction

<!-- tags: abi/calling-convention, wall/register-schedule, construct/bitfield -->

- Function: 0x14dfe0 EnchantmentItem::EnchantmentItemFilterValidationFunction
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 54/81 matching bytes; distance 3.0; comparator fail
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The target preserves the incoming effect pointer in an additional argument register while using the original argument register for the archetype index. The draft retains the effect pointer in its incoming register and chooses another index register, eliminating one pointer move. The target has 24 instructions and the draft 23. The alignment reports no behavior mismatches, which is diagnostic rather than equivalence evidence. The comparator still rejects the size.

The original filter lead is from the permitted sibling, cited per file; table layout and offsets were checked against the assigned local pack. Another routine sharing the filter logic passed separately, but that does not establish this routine's bytes or identity.

## Spellings tried that did not help
- A direct short-circuit condition and the cookbook rule 16 by-value bit-index accessor: 54/81 matching bytes, distance 3.0.
- An inline archetype-table accessor named from the permitted sibling: unchanged.
- Nested conditions with a named boolean flag: unchanged.
- The native Windows permuter, one job with batch 8 and budget 60 seconds, scored 73 candidates. Its best distance stayed 3.0; it produced no zero-distance winner.

## Spelling that fixed it
None. Stopped after three consecutive comparisons without improvement. The failed source and diagnostics remain private for further investigation; no passing source or acceptance claim is made for this routine.
