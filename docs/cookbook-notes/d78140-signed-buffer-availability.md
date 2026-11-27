# 0xd78140 GFxStream::Functiond78140

<!-- tags: construct/serialization, wall/control-flow -->

- Function: 0xd78140 GFxStream::Functiond78140
- Label: GUESS(low)
- Outcome: fixed
- Cause: integer-width-or-cast
- Best score: full native comparator PASS
- Attempts: 2

## What differed
The available-byte test used an unsigned comparison because the position member is unsigned, while the target compares the difference as signed.

## Spellings tried that did not help
Changing the position member width is unnecessary; that member still supplies a zero-extended index.

## Spelling that fixed it
Keep the stored position unsigned and cast only the size-minus-position difference to int before comparing it with one.
