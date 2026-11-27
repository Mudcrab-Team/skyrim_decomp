# 0xf50400 ControllerManagerLeaff50400::RemoveSequence

<!-- tags: method/sibling, sibling/fo4, abi/exception -->

- Function: 0xf50400 ControllerManagerLeaff50400::RemoveSequence
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: prologue-epilogue
- Best score: 51/75 aligned bytes
- Attempts: 1

## What differed
The local reference holder occupied a different incoming-argument home slot from the target. The comparison matched 51/75 aligned bytes and retained the same instruction shape.

## Spellings tried that did not help
- A zero-initialized local reference holder selected the wrong home slot.
- The permuter exhausted its available candidates without improving the distance.

## Spelling that fixed it
None.
