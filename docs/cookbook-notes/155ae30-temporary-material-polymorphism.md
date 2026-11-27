# 0x155ae30 BSWaterShaderMaterial::Function155ae30

<!-- tags: abi/virtual, construct/constructor -->

- Function: 0x155ae30 BSWaterShaderMaterial::Function155ae30
- Label: GUESS(low)
- Outcome: fixed
- Cause: vtable-or-virtual
- Best score: PC comparator PASS (all checks passed)
- Attempts: 4

## What differed

The temporary material must retain its virtual destructor and virtual table. A whole-object storage array hid that known part of its type even when the caller compiled exactly.

## Spellings tried that did not help

The opaque nonpolymorphic declaration produced a passing caller but did not express the observed material type.

## Spelling that fixed it

Declare the virtual destructor and retain only the untouched storage after the virtual table. The constructor and complete destructor remain bound to their observed callees.
