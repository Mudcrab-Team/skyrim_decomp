# 0xf62740 NiColorInterpolator::NiColorInterpolator

- Function: 0xf62740 NiColorInterpolator::NiColorInterpolator
- Label: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
- Outcome: fixed
- Cause: calling-convention
- Best score: 61/61
- Attempts: 4

## What differed

The candidate loaded the sixteen-byte input after the virtual table assignment; the target loaded it before that assignment. The constructor's source parameter type determines when the copy is made.

## Spellings tried that did not help

Passing the input by const reference with a member subobject constructor loaded the input too late. Earlier initialiser-list and body-assignment forms also loaded it too late.

## Spelling that fixed it

Taking the sixteen-byte value by value and constructing the value subobject from it matched. The same change also matched the quaternion constructor at its final comparison. The parameter type remains a hypothesis about the original source, not proof of it.
