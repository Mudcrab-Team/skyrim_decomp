# 0x111af0 Pointer-sized array append

<!-- tags: construct/allocation, construct/destructor, wall/inlining, wall/register-schedule -->

- Function: 0x111af0 Pointer-sized array append
- Label: GUESS(medium)
- Outcome: unsolved
- Cause: register-allocation
- Best score: the scoped candidate was 96 bytes against a 99-byte target and reproduced the prefix through the index check
- Attempts: 28 candidate variants on the representative, followed by 20 held-out comparisons

## What differed

The target ends the allocator functor's lifetime after the append-index call. A scoped functor reproduced that boundary. The remaining difference was the element copy. The target forms the destination address separately, then loads and stores the value. The candidate combines the indexing and store. All 20 held-outs stopped at the function-size check. Separate exception metadata and cleanup comparisons succeeded for those candidates, and their primary unwind spans differed by the same three bytes.

## Spellings tried that did not help

- Function-scope allocator with assignment or placement construction.
- Nested allocator scope, inline append-index helper and immediately invoked lambda.
- Placement construction, allocator traits, explicit copy construction and one-element standard library copies after the scoped call.

## Spelling that fixed it

none
