# 0x302070 TESObjectREFR::Function302070

<!-- tags: construct/loop, wall/register-schedule -->

- Function: 0x302070 TESObjectREFR::Function302070
- Label: GUESS(low)
- Outcome: fixed
- Cause: operand-order
- Best score: PC comparator PASS (all checks passed)
- Attempts: 2

## What differed

The linked-reference walk had the right calls and branches but reversed the operands of its equality test.

## Spellings tried that did not help

Comparing the walked reference to this retained the operand-order difference.

## Spelling that fixed it

Compare this to the walked reference. The call and loop structure remain the same.
