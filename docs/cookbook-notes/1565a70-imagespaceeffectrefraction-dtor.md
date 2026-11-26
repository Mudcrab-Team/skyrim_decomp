# 0x1565a70 ImageSpaceEffectRefraction::dtor_deleting

<!-- tags: method/diagnostic -->

- Function: 0x1565a70 ImageSpaceEffectRefraction::dtor_deleting
- Label: GUESS(low)
- Outcome: fixed
- Cause: other (exception state map)
- Best score: 192/192
- Attempts: 5

## What differed

All bytes matched but the exception state map did not. A conditional release of a texture member sat in the inline destructor of that member.

## Spellings tried that did not help

A parameter destructor that can throw changed the state count. A no-throw getter changed the state map count.

## Spelling that fixed it

Write the conditional release in the owning destructor body and give the member only an out-of-line destructor.
