# 0xf3c270 SphereBVLeaff3c270::operator==

<!-- tags: method/sibling, sibling/fo4, method/binding -->

- Function: 0xf3c270 SphereBVLeaff3c270::operator==
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 72/72 bytes; full comparator pass
- Attempts: 3

## What differed
The qualified operator name was not resolved even though the object defined the equality operator. The first two checks stopped at symbol binding.

## Spellings tried that did not help
- The bare qualified operator name did not select the emitted definition.

## Spelling that fixed it
Record the exact emitted operator symbol in the CI hash header and task. The full PC comparator then passes without a body change.
