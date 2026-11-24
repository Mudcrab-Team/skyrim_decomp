# 0xf7cbd0 FloatControllerCtorLeaff7cbd0::FloatControllerCtorLeaff7cbd0

<!-- tags: method/sibling, sibling/fo4, method/diagnostic -->

- Function: 0xf7cbd0 FloatControllerCtorLeaff7cbd0::FloatControllerCtorLeaff7cbd0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 66/66 aligned bytes and matching exception metadata after binding
- Attempts: 2

## What differed
The first build aligned with the target instructions but the exception cleanup referenced an unbound base destructor, so the comparator could not complete.

## Spellings tried that did not help
- Automatic binding alone did not resolve the cleanup reference in the exception path.

## Spelling that fixed it
Bind the base destructor using the cleanup reference from this function's own pack. The Windows comparator passed.
