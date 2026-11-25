# 0xfaa4e0 ColorModifierCtorLeaffaa4e0::ColorModifierCtorLeaffaa4e0

<!-- tags: method/sibling, sibling/fo4, method/binding -->

- Function: 0xfaa4e0 ColorModifierCtorLeaffaa4e0::ColorModifierCtorLeaffaa4e0
- Label: SIBLING(fo4-private@1b765c70, author-permission)
- Outcome: fixed
- Cause: other
- Best score: 115/115 bytes; full comparator pass
- Attempts: 5

## What differed
Automatic binding missed two destructor calls in exception cleanup: the base and the reference member. Normal-path bindings alone could not complete comparison.

## Spellings tried that did not help
- Binding only the base cleanup exposed the second missing cleanup binding.

## Spelling that fixed it
Bind both cleanup destructors from this function's own private pack. The full PC comparator, including exception metadata, then passes without a body change.
