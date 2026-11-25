# 0x25e640 BGSConstructibleObject::RemoveRequiredItem

<!-- tags: abi/calling-convention, wall/constant, wall/flag-fold -->

- Function: 0x25e640 BGSConstructibleObject::RemoveRequiredItem
- Label: GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: 78/78 bytes; comparator PASS with unwind covered
- Attempts: 3 counted comparisons; 3 invocations total, including binding-only and final-source provenance checks as applicable

## What differed

The callback completed the inventory-removal call, but its success result was produced at a narrower width than the target. Its name and source-level return type remain inferred.

## Spellings tried that did not help

The bool-returning declaration and return true produced 73/78 aligned matching bytes. The call, arguments and absolute count expression were already aligned.

## Spelling that fixed it

Use an unsigned int result in both declaration and definition and return 1. Cookbook rule 66 supplied this hypothesis. The second counted comparison passed; this does not establish the original source-level return type.
