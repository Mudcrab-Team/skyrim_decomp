# 0x1002a50 BSPSysStripUpdateModifier::IsEqual

<!-- tags: abi/virtual, construct/float, method/diagnostic, wall/register-schedule -->

- Function: 0x1002a50 BSPSysStripUpdateModifier::IsEqual
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: unsolved
- Cause: integer-width-or-cast
- Best score: 56/65 aligned matching bytes; comparator FAIL, function-size-mismatch
- Attempts: 5 counted comparisons; 5 invocations total, including binding-only and final-source provenance checks as applicable

## What differed
The reconstructed virtual bool method first checks base equality and then compares the update interval.
The best draft has only a result-width difference in alignment: its success constant uses a byte-sized
result where the target uses a full-width result. This also shifts branch displacements and leaves the
candidate extent different. The bool signature is supported by the permitted naming/prototype sources;
an integer return remains an unproven alternative. Neither the diagnostic score nor those sources
establish a byte match.

## Spellings tried that did not help
The preserved first attempt scored 47/65. Reversing the operands of the symmetric float comparison,
found by a bounded PC permutation run, reached 56/65. The run used one job, batch eight and a sixty-second
budget; its pool exhausted after 81 candidates and two distinct objects, reducing alignment distance
from 1.5 to 0.5. A bool local holding base equality and then the member comparison scored 54/65.
An unsigned result initialized to one and set to zero on failure scored 45/65. Restoring the best
original-signature spelling and final provenance reproduced 56/65 at attempt five, reaching three
consecutive comparisons without improvement. Cookbook rule 66 was retrieved, but changing this
virtual bool method's return type was not justified by the prototype evidence.

- Structural pass: `return base && other->f == f`, `return other->f == f` after an early return, a bool accumulator and an int-typed accumulator all leave the only difference at the true constant (a one-byte move where the target uses a full-width move). Declaring the whole method with an `int` return reproduces the full-width constant and the target's block layout, but then the base call's test and the false constant also widen (the target keeps them byte-wide), so the target mixes a byte-typed base result with a full-width true result. Operand order `other->f == f` matches the target's operand order.

## Spelling that fixed it
none
