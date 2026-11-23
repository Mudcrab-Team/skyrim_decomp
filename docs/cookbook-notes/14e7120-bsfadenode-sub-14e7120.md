# 0x14e7120 BSFadeNode sub_14e7120

- Function: 0x14e7120 BSFadeNode sub_14e7120
- Label: none (unit not published; name is a guess)
- Outcome: unsolved
- Cause: float-codegen
- Best score: 191/283 bytes matching, size 287 vs 283
- Attempts: 6

## What differed

Float register allocation for the distance, alpha and scale values differs and the tail is four bytes longer. Recipe o2-fpfast. Rule 45 family: float code where the target loads and orders operands differently from the source order.

## Spellings tried that did not help

Moving the declaration of alpha; swapping the operand order of the sum.

## Spelling that fixed it

none
