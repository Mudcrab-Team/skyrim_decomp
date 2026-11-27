# 0x397810 BGSPerk::RemovePerk

<!-- tags: abi/virtual, construct/loop, method/diagnostic, method/sibling, sibling/fo4, wall/inlining, wall/register-schedule -->

- Function: 0x397810 BGSPerk::RemovePerk
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: loop-shape
- Best score: distance 2.0 (from 9.5); one loop-alignment byte run and one branch placement left
- Attempts: 5 counted comparisons in total

## What differed

The target retains a pointer and an end pointer across virtual entry removal calls. The raw pointer draft becomes a counted loop with additional arithmetic and saved registers. This reproduces the open cause in cookbook rule 20. The best alignment reported no behaviour mismatches; that observation does not establish equivalence or a byte match.

The body is adapted from the permitted anonymous sibling's RemovePerk walk, with the local target supplying the array offsets and virtual slot. The sibling remains a shape and name lead.

## Spellings tried that did not help

- A nonempty guard followed by a raw pointer inequality loop: 46/81 matching bytes, distance 9.5, candidate extent 104.
- Changing pointer inequality to an ordered comparison: 46/81, distance 10.5, extent 104.
- A small iterator with begin/end factories and inline dereference, increment and inequality: 46/81, distance 16, extent 112. The factories remained calls and their references could not be bound from this pack.
- Force-inlining the tiny factories with a hot-traversal justification: unchanged at 46/81, distance 16, extent 112. No binding was invented for the extra calls.

- The `while (it != end)` form and an index form made the compiler rewrite the pointer walk into a counted loop with a clamped trip count (extra arithmetic, 104 bytes against 81). A `do { } while (it != end)` form lost the target's second guard (distance 2.5).
- Taking the element and advancing the pointer in one statement inside the loop body (`BGSPerkEntry* entry = *it++;`) keeps the pointer walk and both guards and brings the distance to 2.0. What is left: the loop head is padded to an aligned address in the candidate and the target's increment follows the call.

## Spelling that fixed it
None; the post-increment form is the best spelling and does not match yet.
