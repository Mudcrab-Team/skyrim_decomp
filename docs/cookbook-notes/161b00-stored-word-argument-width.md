# 0x161b00 ExtraDataList::Function161b00

<!-- tags: abi/calling-convention, wall/layout -->

- Function: 0x161b00 ExtraDataList::Function161b00
- Label: GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: PC comparator PASS (all checks passed)
- Attempts: 3

## What differed

The callee stores a word, but the incoming value remains an unsigned integer until that store. A narrow formal parameter introduced a zero extension.

## Spellings tried that did not help

Narrowing the formal parameter changed the register preparation; widening both the parameter and stored field changed the store width.

## Spelling that fixed it

Keep the parameter unsigned and the payload field uint16_t. The assignment performs the final narrowing.
