# 0xfa7ed0 NiPSysBoundUpdateModifier::IsEqual

<!-- tags: wall/register-schedule, method/diagnostic -->

- Function: 0xfa7ed0 NiPSysBoundUpdateModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
- Outcome: fixed
- Cause: operand-order
- Best score: 61/61 aligned matching bytes; local comparator PASS
- Attempts: 3

## What differed

The initial handwritten equality check matched 53/61 bytes. Reference bindings agreed, behavior diagnostics reported no mismatches, and the remaining classified differences were register choices in the final word comparison. Cookbook rule 42 was applicable even though equality makes the operand order semantically interchangeable.

## Spellings tried that did not help

A one-worker PC permutation search scored 49 candidates and exhausted its pool without improving distance 1. Naming the inherited equality result and returning that local reduced the ordinary comparison to 34/61 matching bytes and changed the function extent.

## Spelling that fixed it

Keep both early false returns and compare the other object's update interval against this object's interval. Reversing only those equivalent equality operands closed the ordinary comparator on the third compare. The method remains handwritten and uses no sibling middleware body.
