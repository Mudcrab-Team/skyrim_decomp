# 0x1198e0 Scrap-backed array cleanup

<!-- tags: construct/destructor, wall/register-schedule -->

- Function: 0x1198e0 Scrap-backed array cleanup
- Label: GUESS(medium)
- Outcome: unsolved
- Cause: branch-layout
- Best score: the size recipe emitted 56 bytes against a 59-byte target with the same call and branch structure
- Attempts: 9 candidate and recipe combinations

## What differed

The target clears the size after releasing live allocation storage. Both branches share a final call into the size subobject. The default recipe duplicated the exit paths. The size recipe shared the exit paths but used a memory read-modify-write to clear the size where the target uses a direct store.

## Spellings tried that did not help

- Separate cleanup method and C++ destructor forms.
- Declaring the final helper with and without a nonthrowing exception specification.
- The existing size-optimized recipe to merge the two final call paths.

## Spelling that fixed it

none
