# 0x5d1400 MagicTarget::DispelAllSpells_140552E10

<!-- tags: abi/exception, abi/virtual, construct/loop, method/diagnostic, wall/control-flow -->

- Function: 0x5d1400 MagicTarget::DispelAllSpells_140552E10
- Label: CRASHLOGGER_PDB(59818@2026.10.24)
- Outcome: fixed
- Cause: prologue-epilogue
- Best score: 101/101 code bytes; comparator PASS, unwind covered
- Attempts: 2 counted comparisons after the structural reading

## What differed
The target stores an exception-state slot, places a visitor object with a virtual-table pointer and a flag byte above it, and walks the effect list calling the visitor through its table. The earlier draft used a plain struct and a hand-made table, so there was no frame slot and the call shape differed. The loop is the one of 0x5d18b0.

## Spellings tried that did not help
- An empty destructor on the plain struct.
- A polymorphic visitor used directly in the function: the compiler resolved Accept statically and emitted a direct call.

## Spelling that fixed it
A polymorphic visitor class with an inline empty virtual destructor (the exception-state slot appears with it), and a list-walk helper that takes the visitor by base reference so Accept stays a virtual call. The walk is the 32-bit result seed and `while (node && result == 1)` of 0x5d18b0. The virtual-table address bound without a hint.
