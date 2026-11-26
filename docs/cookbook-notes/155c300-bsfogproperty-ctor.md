# 0x155c300 BSFogProperty::ctor

<!-- tags: method/diagnostic -->

- Function: 0x155c300 BSFogProperty::ctor
- Label: GUESS(low)
- Outcome: unsolved
- Cause: instruction-order
- Best score: 216/229 aligned
- Attempts: 2

## What differed

A distance is a constant minus the depth times a second constant. The target loads the depth first and multiplies by a memory constant. With external constant floats the compiler loads the constant first. The same holds for the clone function 0x155c1a0.

## Spellings tried that did not help

A local for the scaled depth, inline helpers with value and reference parameters, and reversed operand order in the source.

## Spelling that fixed it

none. A test compile shows that float literals give the target order; the two literal values are not known from the listing.
