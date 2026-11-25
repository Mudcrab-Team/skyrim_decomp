# 0xf9d990 FloatLinkLeaff9d990::LinkObject

<!-- tags: method/sibling, sibling/fo4, wall/register-schedule -->

- Function: 0xf9d990 FloatLinkLeaff9d990::LinkObject
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: unsolved
- Cause: register-allocation
- Best score: 78/88 aligned bytes
- Attempts: 1

## What differed
The target saves a nonvolatile register to a different parameter home slot, which also changes the unwind record.

## Spellings tried that did not help
- The initial source matched the instruction sequence apart from the save and restore offsets.
- The permuter explored 408 candidates without improving the baseline.

## Spelling that fixed it
None.
