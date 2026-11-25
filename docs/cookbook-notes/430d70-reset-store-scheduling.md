# 0x430d70 BSFaceGenKeyframeExclusive::Reset

<!-- tags: abi/virtual, construct/float, method/diagnostic, wall/register-schedule -->

- Function: 0x430d70 BSFaceGenKeyframeExclusive::Reset
- Label: GUESS(low)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 55/64 aligned matching bytes; distance 1; comparator FAIL
- Attempts: 4 counted comparisons; 4 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The target and candidate have 18 instructions and the same size. The candidate loads the virtual table and prepares the invalidation argument before clearing the field, whereas the target clears the field first. The original body was reconstructed using authorized local binary analysis and community declarations; the operation names remain guesses.

## Spellings tried that did not help
- Direct zero assignment: 55/64, distance 1.
- Self-subtraction under the fast-float recipe: unchanged at 55/64.
- An inline invalidation forwarding helper: unchanged at 55/64.
- Restoring the direct spelling: unchanged at 55/64.
- Bounded permutation: 73 candidates, no distinct improved object.

## Spelling that fixed it
None. Three consecutive comparisons without improvement ended drafting. Cookbook rule 48 supplies the already-used fast-float recipe; it does not close this scheduling residue.
